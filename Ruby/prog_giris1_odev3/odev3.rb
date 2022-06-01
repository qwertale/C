puts "Sisteme Hoş Geldiniz"
loop  do
puts "Öğretmen Girişi İçin 1'e Basınız."
puts "Öğrenci Girişi İçin 2'ye Basınız."
puts "Çıkış İçin Herhangi Bir Tuşa Basınız."
kullanici = gets.chomp
if kullanici == "1"
    loop do
        c = File.read("loginteacher.txt").split("\n")
        d = c.map do |e|
            e.split(",")
        end
        $ogretmen = {}
        d.each do |key ,value|               
            $ogretmen[key] = value
        end
        puts "Kullanıcı Adınızı Giriniz:"
        $girilen1 = gets.chomp
        if $ogretmen.key? $girilen1
            puts "Şifrenizi Giriniz:"
            $girilen2 = gets.chomp
            if $ogretmen[$girilen1] == $girilen2
                puts "Başarıyla Giriş Yapıldı."
                break
            else puts "Şifreniz Hatalıdır."
            end
        else puts "Kullanıcı Adınız Hatalıdır."
        end
    end
    loop do
        c = File.read("students.txt").split("\n")
        d = c.map do |e|
            e.split(",")
        end
        $ogrencino1 = {}
        d.each do |key ,value|
            $ogrencino1[key] = value
        end
        c = File.read("lessonCodes.txt").split("\n")
        d = c.map do |e|
            e.split("\s-\s")
        end
        $derscodu1 = {}
        d.each do |key ,value|
        $derscodu1[key] = value
        end
        puts "Ders notu Girmek İçin 1'e , Ders Notu Güncellemek İçin 2'ye ,Çıkmak İçin Herhangi Bir Tuşa Basınız."
        girilen3 = gets.chomp
        if girilen3 == "1"
            puts "Öğrenci Numarası Giriniz: "
            $no1 =gets.chomp
            if $ogrencino1.key? $no1
                puts "Ders Kodu Giriniz"
                $girilen2 = gets.chomp
                if $derscodu1.value? $girilen2
                    puts "Ders Notu Giriniz:"
                    $dersnotu1 = gets.chomp
                    File.open("#{$no1}.txt","a+") do |dosya|
                        dosya.puts "#{$girilen2},#{$dersnotu1}"
                    end
                else puts "Böyle Bir Ders Yoktur"
                    break
                 end
            else puts "Böyle Bir Öğrenci Numarası Bulunmamaktadır."
                break
            end
        elsif girilen3 == "2" 
            puts "Öğrenci Numarası Giriniz: "
            $no1 =gets.chomp
            if $ogrencino1.key? $no1
                puts "Ders Kodu Giriniz"
                $girilen2 = gets.chomp
                if $derscodu1.value? $girilen2
                    puts "Ders Notu Giriniz:"
                    $dersnotu1 = gets.chomp
                    File.open("#{$no1}.txt","w+") do |dosya|
                        dosya.puts "#{$girilen2},#{$dersnotu1}"
                    end
                else puts "Böyle Bir Ders Yoktur"
                    break
                end    
            else puts "Böyle Bir Öğrenci Numarası Bulunmamaktadır."
                break
            end
        else puts "Sistemden Çıkılıyor."
            break
        end
    end
elsif kullanici == "2"
    loop do
        c = File.read("students.txt").split("\n")
        d = c.map do |e|
            e.split(",")
        end
        $ogrencino1 = {}
        d.each do |key ,value|
            $ogrencino1[key] = value
        end
        c = File.read("lessonCodes.txt").split("\n")
        d = c.map do |e|
            e.split("\s-\s")
        end
        $derscodu1 = {}
        d.each do |key ,value|
        $derscodu1[key] = value
        end
    puts "Öğrenci Numaranızı Giriniz:"
    $girilen4 =gets.chomp
    if $ogrencino1.key? $girilen4
        puts "Şifrenizi Giriniz"
        $girilen5 = gets.chomp
        if $ogrencino1[$girilen4] == $girilen5
            puts "Öğrenmek İstediğiniz Dersin Kodunu Giriniz. Bütün Derslerin Notunu Öğrenmek İçin 1'e Basınız."
            $girilen6 = gets.chomp
            c = File.read("#{$girilen4}.txt").split("\n")
            d = c.map do |e|
                e.split(",")
            end
            $girilennot1 = {}
            d.each do |key,value|
                $girilennot1[key] = value
            end
            if $girilen6 == "1"
                puts $girilennot1
                break
            elsif $derscodu1.value? $girilen6
                puts $girilennot1[$girilen6] 
                 break
            else puts "Hatalı Giriş Yaptınız."
                break
            end
        else puts "Hatalı Şifre Girdiniz"
            break
        end
    else puts "Böyle Bir Numara Bulunmamaktadır."
        break
    end
    end
else puts "Programdan Çıkılıyor"
    exit
end
end   