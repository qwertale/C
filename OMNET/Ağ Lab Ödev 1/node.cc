#include <string.h>
#include <omnetpp.h>
#include <stdlib.h>
#include <stdio.h>
#include <array>

#define ROOT_NODE 49  // Kök Düğüm İndisi

#define LAYER  new cMessage( 1 , 2) // Renk 2 = Mavi
#define ACK    new cMessage( "ack" , 1) // Renk 1 = Yeşil
#define REJECT new cMessage( "reject" , 2) // Renk 0 = Kırmızı

using namespace omnetpp;

class Dugum : public cSimpleModule
{
    int parent_gate = -1;
    char my_layer[10] = "51";
    std::vector< cGate* > childs;
    std::vector< cGate* > others;

  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

// The module class needs to be registered with OMNeT++
Define_Module(Dugum);

void Dugum::initialize()
{
    if (getIndex() == ROOT_NODE ){
        //root if e girer.
        my_layer[0] = '0';
        scheduleAt(0.0, new cMessage( "0")); // Kendine mesaj gönder ( ilk mesajların izlenebilmesi için )
    }
}

void Dugum::handleMessage(cMessage *msg)
{
    cGate *gelen_kapi = msg->getArrivalGate();
    EV << getIndex() <<"düğümünün kapı sayısı" << this->gateSize("kapi$o") << "\n" ;
    EV << getIndex() <<"düğümününe gelen mesaj" << msg<< "\n" ;

    if( strcmp(msg->getName(),"ack") != 0 && strcmp(msg->getName(),"reject") != 0){ // mesaj ack ya da reject değil ise

        int gelenlayer = atoi(msg->getName()); // mesajı int e çevir
        int layer = atoi(my_layer);

        EV << getIndex() <<"düğümünün layer ı " << layer << "\n";
        EV << getIndex() <<"düğüme gelen layer " << gelenlayer << "\n";


        if(layer  > gelenlayer ){
                if(gelen_kapi == NULL){
                    // root a ilkleme gelmiş
                    parent_gate = -2;
                    EV << getIndex() << "çalışıyo" << "\n" ;
                    for(int i = 0 ; i < this->gateSize("kapi$o") ; i++){
                        if(msg->arrivedOn("kapi$i", i)){
                            continue;
                        }else{
                            int ret = sprintf(my_layer, "%d", layer);
                            send( new cMessage(my_layer) , "kapi$o", i);
                        }
                    }
                }else{
                    //ilkleme mesajı haricindeki tüm probe mesajları

                        parent_gate = gelen_kapi->getIndex();
                        send(ACK, "kapi$o", parent_gate);

                        layer = gelenlayer + 1; // layer ım parentımın layerından bir fazla oldu
                        EV << getIndex() <<"düğümünün son layer ı " << layer << "\n";

                        for(int i = 0; i < this->gateSize("kapi$o") ; i++){
                            if(msg-> arrivedOn("kapi$i", i)){
                                continue; //parent a probe gitmesin
                            }else{
                                int ret = sprintf(my_layer, "%d", layer);
                                send(new cMessage(my_layer), "kapi$o", i);
                            }
                        }

                }

            }else if(layer < gelenlayer ){
                send(REJECT, "kapi$o", gelen_kapi->getIndex());
            }
      }else if(strcmp(msg->getName(),"ack") == 0){
               childs.push_back(gelen_kapi);
               EV << getIndex() <<"düğümünün çocuklarına eklendi "<< childs.size();
      }else if(strcmp(msg->getName(),"reject") == 0){
               others.push_back(gelen_kapi);
               EV << getIndex() <<"düğümünün others a eklendi "<< others.size();
      }
}
