class Hasta_Covid_19
    attr_reader :tcnum, :name, :lastname, :gender, :age, :symptom, :disease, :province, :contact
    @@hastasayısı = 0
    def initialize(tcno, ad, soy, cins, yas, belirti, hastalık, il, temas)
        @tcnum=tcno 
        @name=ad
        @lastname=soy
        @gender=cins
        @age=yas
        @symptom=belirti
        @disease=hastalık
        @province=il
        @contact=temas
        @@hastasayısı += 1
    end
    def listele()
        printf( "#{tcnum} \n, #{name} \n,  #{lastname} \n, #{gender} \n, #{age} \n, #{symptom} \n, #{disease} \n, #{province} \n, #{contact} \n ")

end

$hastalar =[0, 1, 2, 3, 4, 5]
$hastano = 0
$toplamtemas= 0

print "Sağlık Bakanlığı Covid-19 Bilgi Sistemine Hoş Geldiniz.\n"
while true
    print "Komut Giriniz="
    $komut = gets.chomp

    while ($komut == "EKLE" || $komut == "LISTELE" || $komut == "EXIT")
        if $komut == "EKLE"
            $hastano = ($hastano + 1) 
            printf "Hatsanın TC numarasını giriniz :"
            tcno =gets.chomp
            printf "Hastanın adını giriniz :"
            ad =gets.chomp
            printf "Hastanın soyadını giriniz :"
            soy =gets.chomp
            printf "Hastanın cinsiyetini giriniz (Erkek/Kadın) :"
            cins =gets.chomp
            printf "Hastanın yaşını giriniz :"
            yas =gets.chomp
            printf "Hastanın varsa semptomlarını belirtiniz yoksa 0 bilgisi giriniz :"
            belirti =gets.chomp
            printf "Hastanın bulunduğu ili giriniz :"
            il= gets.chomp
            printf "Hastanın varsa kronik rahatsızlığını belirtiniz yoksa 0 bilgisi giriniz :"
            hastalık =gets.chomp
            printf "Hastanın temasta bulunduğu tahmini kişi sayısını belirtiniz yoksa 0 bilgisi giriniz :"
            temas =gets.chomp
            $toplamtemas = ($toplamtemas + temas.to_i)

            $hastalar[$hastano] = Hasta_Covid_19.new(tcno, ad, soy, cins, yas, belirti, hastalık, il, temas)
            #hasta1.kurucu(tcno, ad, soy, cins, yas, belirti, hastalık, il, yas)
            break
        elsif $komut == "LISTELE" 
            hastalistele = $hastano
            while ( hastalistele != 0)
                $hastalar[hastalistele].listele()
                printf( "Toplam enfekte olması muhtemel kişi sayısı :#{$toplamtemas} \n")
                printf ("Toplam hasta sayısı : #{@@hastasayısı}\n")
                hastalistele = ( hastalistele - 1 )
            end
            break
        elsif $komut == "EXIT"
            printf "Sağlıklı günler dileriz :)"
            exit
        end
    end
    if ($komut != "EKLE" && $komut != "LISTELE" && $komut != "EXIT")
        print "Hatalı bir komut girdiniz\n"
    end
end
exit
end