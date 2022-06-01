puts "Sisteme Hoş Geldiniz"
puts "Sistemi kullanmak için gerekli komutlar aşağıda listelenmiştir"
puts "Giriş yapmak için komut : Login"
puts "İngilizceden Türkçeye kelimeler için komut : EngTr"
puts "Türkçeden İngilizceye kelimeler için komut : TrEng"
puts "Çıkmak için komut : Exit"
loop do
puts"Komut Giriniz:"
alınan = gets.chomp
    if alınan == "Login"
       break
    else 
       puts "Önce Sisteme Giriş Yapılmalıdır"
    end 
end
loop do
c = File.read("login.txt").split("\n")
d = c.map do |e|
    e.split(",")
end
$login = {}
d.each do |key ,value|
    $login[key] = value
end
    print "Lütfen Kullanıcı Adınızı Giriniz:"
    $username = gets.chomp
    if $login.key? $username 
         break
        else  puts "Kullanıcı Adınız Hatalıdır "
        end 
    end

loop do
    print "Lütfen Şifrenizi Giriniz:"
    password = gets.chomp
    if $login[$username] == password
        puts "Başaryla Giriş yapıldı"
       break
    else puts "Şifreniz Hatalıdır " 
    end 
end 


loop do 
a = File.read("eng_tur_words.txt").split("\n")
b = a.map do |i|
    i.split(",")
    end 
$engtr = {}
$treng = {}
b.each do |l , k|
    $engtr[l] = k
    end
    b.each do |h , j|
        $treng[j] = h
    end

    print "Lütfen Komut Giriniz: "
    $komut = gets.chomp
    if $komut == "EngTr" 
      loop do
         print "Lütfen İngilizce Kelime Giriniz: "
         $kelime = gets.chomp
        if $engtr.key? $kelime
            anlamsız =  $engtr[$kelime]
            puts anlamsız
        elsif $kelime == "TrEng"
            break 
        else puts " Hatalı Kelime Girdiniz " 
            break
        end
        end
    
    elsif $komut == "TrEng"
            loop do 
                print "Lütfen Türkçe Kelime Giriniz: "
                $word = gets.chomp
                if $treng.key? $word
                    anlamsız2 = $treng[$word]
                    puts anlamsız2
                elsif $word == "EngTr"
                    break
                else puts " Hatalı Kelime Girdiniz "   
                    break         
                end    
                end
    elsif $komut == "Exit"
        puts "Güle Güle " 
        exit          
    else  puts " Hatalı Kelime Girdiniz "         
    end 
end    