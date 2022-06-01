import ned.DelayChannel;


simple Dugum
{
    gates:
        inout kapi[];

}

channel Hızlı extends DelayChannel
{
    @display("ls=#EF2929");
    delay = 1ms;
}

network DFS2
{
    parameters:
        int dugumSayisi = 51;
        int yarisi = int(dugumSayisi / 2);
        int rastgele = 1;

        @display("bgb=873,354");
    submodules:
        dugum[dugumSayisi]: Dugum {
            @display("p=265.2925,127.165");
        }
    connections:
                for i=0..(yarisi-2) {
            dugum[i].kapi++ <--> Hızlı <--> dugum[i+1].kapi++;					// 24 bağlantı
            dugum[i].kapi++ <--> Hızlı <--> dugum[dugumSayisi-i-1].kapi++;		// 24 bağlantı
        }
        dugum[0].kapi++ <--> Hızlı <--> dugum[1].kapi++;						// toplam 57 bağlantı simülaston çalıştığında 114 mesaj demek
        dugum[0].kapi++ <--> Hızlı <--> dugum[44].kapi++;
        dugum[0].kapi++ <--> Hızlı <--> dugum[25].kapi++;

        dugum[1].kapi++ <--> Hızlı <--> dugum[12].kapi++;
        dugum[1].kapi++ <--> Hızlı <--> dugum[31].kapi++;
        dugum[1].kapi++ <--> Hızlı <--> dugum[14].kapi++;

        dugum[2].kapi++ <--> Hızlı <--> dugum[39].kapi++;
        dugum[3].kapi++ <--> Hızlı <--> dugum[44].kapi++;
        dugum[4].kapi++ <--> Hızlı <--> dugum[35].kapi++;
}