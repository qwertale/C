notlar = [["ahmet",50.0,60.0], ["mehmet",60.0,90.0], ["temel",70.0,20.0], ["dursun",0.0,100.0], ["fadime",100.0,100.0], ["zeynep", 30.0,30.0]]
not_ort = []
not_ort = notlar.select do |ogrenci, vize, final|
   ogrenci  && not_ort << vize * 0.4 + final * 0.6 
  end
puts "Not Ortalamaları = #{not_ort}"

genel_ort = 0
notlar.each do |ogrenci, vize, final|
  genel_ort = genel_ort + ((vize * 0.4 + final * 0.6) / notlar.size )
  end

cana_giren = []
cana_giren = notlar.select do |ogrenci, vize, final|
   20 < (vize * 0.4 + final * 0.6) && (vize * 0.4 + final * 0.6) < 80 
 end
puts "Çana Girenler = #{cana_giren}"
 
dersi_gecenler = [ ] 
notlar.each do |ogrenci, vize, final| 
  ortalama = (vize * 0.4 + final * 0.6 )
    if final > 50.0 && ortalama > 40.0 
        dersi_gecenler << ogrenci
        puts " #{ogrenci} isimli öğrenci #{ortalama} not ortalaması ile dersi geçmiştir" 
       if final < 50.0 && ortalama < 40
        puts " #{ogrenci} isimli öğrenci #{ortalama} not ortalaması ile dersten kalmıştır" 
       end
    end
 end 
puts " Toplam öğrenci sayısı = #{notlar.size}"
puts "Dersi geçen öğrenci sayısı #{ dersi_gecenler.size } "
puts "Genel ortalama = #{genel_ort}"

can_ort = 0
cana_giren.each do |ogrenci, vize, final|
  can_ort = can_ort + ((vize * 0.4 + final * 0.6) / cana_giren.size )
end