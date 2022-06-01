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
        int dugumSayisi = 6;

        @display("bgb=873,354");
    submodules:

        E: Dugum {
            @display("p=361.7625,55.90875");
        }
        C: Dugum {
            @display("p=705.985,55.90875");
        }
        G: Dugum {
            @display("p=83.315,246.65625");
        }
        A: Dugum {
            @display("p=361.7625,246.65625");
        }
        F: Dugum {
            @display("p=83.315,55.90875");
        }
        B: Dugum {
            @display("p=705.985,246.65625");
        }
    connections:

        F.kapi++ <--> Hızlı <--> E.kapi++;
        E.kapi++ <--> Hızlı <--> C.kapi++;
        G.kapi++ <--> Hızlı <--> A.kapi++;
        A.kapi++ <--> Hızlı <--> B.kapi++;
        C.kapi++ <--> Hızlı <--> B.kapi++;
        E.kapi++ <--> Hızlı <--> A.kapi++;
        F.kapi++ <--> Hızlı <--> G.kapi++;
        E.kapi++ <--> Hızlı <--> B.kapi++;
}
