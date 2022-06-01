#include <string.h>
#include <omnetpp.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define ROUND new cMessage("token", 1)  //round mesajı 200 300 arası
#define COLOUR new cMessage("color", 2)  // renkler 100 200 arası
#define ID new cMessage("id", 3)         // id ler 0 100 arası
#define DISCARD new cMessage("discard", 3)

using namespace omnetpp;

class Dugum : public cSimpleModule
{
    int max_komsu_id = -1;     // max id ye sahip komşumun id si
    int max_komsu = -1;        // max id ye sahip komşumun kapısı
    int my_color = -1;      // düğüm renklerini tutmak için
    char my_temp[10] = "51"; // renk mesajlarını gönderebilmek için
    char my_id[10] = "0";   // id mesajlarını gönderebilmek için
    int ids_sent = 0;    // düğüme gelen mesajlarını saymak için
    int my_id2 = 0;     // düğüm id lerini tutmak için
    std::vector< int > komsular;
    std::vector< int > silinen_komsular;
    std::vector< int > received;
    std::vector< int > alinan_renkler;
    int renkler[100];   // 100 den başlayacak ( ID lerin 100den küçük olacağı tahmini ile)
    bool colored = false;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Dugum);

void Dugum::initialize()
{
    my_id2 = this->getIndex();
    EV << getIndex() << "dugumunun ID:"<< my_id2 <<"\n";
    max_komsu_id = my_id2;
    for(int i = 0; i < 100; i++){
        renkler[i] = i + 100;   // renkler yerine 100 den 200 e numaralar kullandım // ilk 100 id lere ayrıldı
    }

    int ret = sprintf(my_id, "%d", my_id2);
    for(int i = 0; i < this->gateCount() / 2; i++){
        send( new cMessage(my_id) , "kapi$o", i);
    }

}

void Dugum::handleMessage(cMessage *msg){

    cGate *arrival_gate = msg->getArrivalGate();
    int gelen_kapi = arrival_gate->getIndex();

    EV << getIndex() <<" mesajı aldı \n";


if( strcmp("discard",msg->getName()) != 0 ){

    int gelennumara = atoi(msg->getName()); // mesajı int e çevir

    if(gelennumara < 100 ){               //mesaj 100 den küçük ise index olur
        EV << getIndex() <<" dugumune gelen mesaj ID mesajı ve "<< gelennumara <<"\n";
        if(max_komsu_id < gelennumara){      //benim ID m gelenden küçükse
            max_komsu_id = gelennumara;       // max ID gelen olsun
            ids_sent++;
            if(ids_sent == this->gateCount() / 2 ){ // gelen id mesajları bitmişse
                scheduleAt(1.0, new cMessage("201")); // 1. round başlasın
            }
        }
    }else if(200 < gelennumara && gelennumara < 300) { // mesaj 200 ve 300 arasında ise round olur
        EV << this->getName() <<" dugumune gelen mesaj ROUND mesajı ve "<< gelennumara <<"\n";
        if(!colored){
            if(max_komsu_id == gelennumara){    // max ID benim ID m ise
                for(int i = 100;i < 200; i++){
                    if( (std::count(this->alinan_renkler.begin(), this->alinan_renkler.end(), i )) ){ // alınan renkler hariç
                        continue;
                    }else{
                        EV << this->getName() <<" max ID benim renk seciyorum \n";
                        my_color = i; // bir renk al
                        break;
                    }
                }
                colored = true;
                for(int i = 0;i < this->gateCount() / 2; i++){
                    if( std::count(this->silinen_komsular.begin(), this->silinen_komsular.end(), i ) ){ //silinen komşular hariç
                        continue;
                    }else{
                        EV << this->getName() <<" renk mesajı atiliyor \n";
                        int ret2 = sprintf(my_temp, "%d", my_color);
                        send( new cMessage(my_temp) , "kapi$o", i);  // komşulara rengini gönder
                    }
                }
            }
        }else{  // if(200 > gelennumara && gelennumara < 300)
            for(int i = 0;i < this->gateCount() / 2; i++){
                if( std::count(this->silinen_komsular.begin(), this->silinen_komsular.end(), i ) ){ //silinen komşular hariç
                    continue;
                }else{
                    EV << this->getName() <<" max ID ben değilim DISCARD atiliyor \n";
                    send( new cMessage("discard") , "kapi$o", i);  // komşulara rengini gönder
                }
            }
        }

    }else if(100 < gelennumara && gelennumara < 200){    // mesaj 100ve 200 arasında ise renk mesajıdır
        EV << this->getName() <<" dugumune gelen mesaj RENK mesaji ve "<< gelennumara <<"\n";
        received.push_back( gelen_kapi );
        alinan_renkler.push_back( gelennumara );
        silinen_komsular.push_back( gelen_kapi );
    }
}else if(strcmp("discard",msg->getName()) == 0 ){
    EV << this->getName() <<" dugumune gelen mesaj DISCARD mesaji ve "<< msg <<"\n";
    received.push_back( gelen_kapi );

}

}
