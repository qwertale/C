#include <string.h>
#include <omnetpp.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define ROOT_NODE  "F"                      // Kök Düğüm İndisi


#define TOKEN    new cMessage("token",    1) // Renk 1 = Yeşil


using namespace omnetpp;

class Dugum : public cSimpleModule
{
    int parent_gate = -1;
    std::vector< int > visited;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    int sayac = 0;
};

// The module class needs to be registered with OMNeT++
Define_Module(Dugum);

void Dugum::initialize()
{
    EV << getName() << "dugume girdi\n";
    // parent_name = "";
    parent_gate = -1;
    //for(int i = 0; i < this->gateCount() / 2; i++){
      //  this->visited.push_back(0);
    //}
    if (strcmp(this->getName(), ROOT_NODE ) == 0) { // (this->getId() == ROOT_NODE)
        EV << getName() << "roota girdi\n";
        this->parent_gate = -2;            //ROOT_NODE;
        this->visited.push_back(0);               //  this->visited[0] = 1;
        send(TOKEN, "kapi$o", 0);    // msg1->dup()
    }
}

void Dugum::handleMessage(cMessage *msg){
    sayac++;
    cGate *arrival_gate = msg->getArrivalGate();
    int gelen_kapi = arrival_gate->getIndex();


    int kapi_sayisi = this->gateSize("kapi$o");
    // EV << getName() <<"düğümünün kapı sayısı" << kapi_sayisi;
    int temp = 0;

    if(this->parent_gate == -1){
        EV << this->getName() << "parentını mesajı atan yaptı\n";
        this->parent_gate = gelen_kapi;
    }
    if(this->visited.size()==kapi_sayisi-1 && !(std::count(this->visited.begin(), this->visited.end(), this->parent_gate))){
        EV << this->getName() <<"nın parentı hariç tüm komşuları ziyaret edilmiş\n" ;
        if (strcmp(getName(), ROOT_NODE ) == 0){
            if(this->visited.size()==kapi_sayisi){
                //EV << this->getIndex() <<"nodu roota geri geldi bitiriyor\n" ;
                //finish();
                //endSimulation();
            }else{
                EV << this->getName() <<" parent a mesaj atıyor 'wink'\n" ;
                send(TOKEN, "kapi$o", gelen_kapi);
                this->visited.push_back(gelen_kapi);
            }
        }else{
            EV << this->getName() <<" parent a mesaj atıyor\n" ;
            send(TOKEN, "kapi$o", this->parent_gate);
            this->visited.push_back(this->parent_gate);
            exit;
        }
    }else{
        if(gelen_kapi != this->parent_gate && !(std::count(this->visited.begin(), this->visited.end(), gelen_kapi))){
            EV <<"mesajı atan parent değil ve ziyaret edilenler listesinde yok \n" ;
            temp = gelen_kapi;
        }else{
            EV <<"mesajı atan parent ve komşu seç \n" ;
            for(int i = 0; i < kapi_sayisi; i++){        // tüm kapılara bak
                if(i == this->parent_gate || std::count(this->visited.begin(), this->visited.end(), i)){ //parent ise veya ziyaret edilmişler ise
                    continue;                                       // atla
                }
                else{ // parent veya ziyaret edilmiş değiller ise
                    temp = i;                                      //  q <-- j
                    i = kapi_sayisi; // for döngüsü bitsin
                }
             }
        }
        if(this->visited.size()==kapi_sayisi && !(std::count(this->visited.begin(), this->visited.end(), this->parent_gate))){
            EV << this->getName() <<"nın parentı hariç tüm komşuları ziyaret edilmiş\n" ;
            if (strcmp(getName(), ROOT_NODE ) == 0){
                if(this->visited.size()==kapi_sayisi){
                    EV << this->getIndex() <<"nodu roota geri geldi bitiriyor\n" ;
                    finish();
                    endSimulation();
                    //continue;
                }
             }
        }

        EV << this->getName() <<" komşuya mesaj atıyor komşu:"<< temp <<"\n";
        this->visited.push_back(temp);                                // q ziyaret edilenlere ekle
        send(TOKEN, "kapi$o", temp );                           // q ya token at

    }
}

