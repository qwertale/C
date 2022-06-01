#include <string.h>
#include <omnetpp.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define ROOT_NODE  49


#define TOKEN    new cMessage("token",    1) // Renk 1 = Yeşil

using namespace omnetpp;

class Dugum : public cSimpleModule
{
    int parent_gate = -1;
    std::vector< int > visited;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Dugum);

void Dugum::initialize()
{
    EV << getIndex() << "dugume girdi\n";
    parent_gate = -1;
    if (this->getIndex() == ROOT_NODE) {
        EV << getIndex() << "roota girdi\n";
        this->parent_gate = -2;
        this->visited.push_back(0);
        send(TOKEN, "kapi$o", 0);
    }
}

void Dugum::handleMessage(cMessage *msg){
    cGate *arrival_gate = msg->getArrivalGate();
    int gelen_kapi = arrival_gate->getIndex();
    int kapi_sayisi = this->gateSize("kapi$o");
    int temp = 0;

    if(this->parent_gate == -1){
        EV << this->getIndex() << "parentını mesajı atan yaptı\n";
        this->parent_gate = gelen_kapi;
    }
    if(this->visited.size()==kapi_sayisi-1 && !(std::count(this->visited.begin(), this->visited.end(), this->parent_gate))){
        EV << this->getIndex() <<"nın parentı hariç tüm komşuları ziyaret edilmiş\n" ;
        if (this->getIndex() == ROOT_NODE){
           if(this->visited.size()==kapi_sayisi){

           }else{
                EV << this->getIndex() <<" parent a mesaj atıyor 'wink'\n" ;
                send(TOKEN, "kapi$o", gelen_kapi);
                this->visited.push_back(gelen_kapi);
            }
        }else{
            EV << this->getIndex() <<" parent a mesaj atıyor\n" ;
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
            EV << this->getIndex() <<"nın parentı hariç tüm komşuları ziyaret edilmiş\n" ;
            if (this->getIndex() == ROOT_NODE){
                if(this->visited.size()==kapi_sayisi){
                    EV << this->getIndex() <<"nodu roota geri geldi bitiriyor\n" ;
                    finish();
                    endSimulation();

                }
             }
        }

        EV << this->getIndex() <<" komşuya mesaj atıyor komşu:"<< temp <<"\n";
        this->visited.push_back(temp);                                // q ziyaret edilenlere ekle
        send(TOKEN, "kapi$o", temp );                           // q ya token at

    }
}



