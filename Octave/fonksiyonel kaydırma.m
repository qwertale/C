% yukarı-aşağı yada sağ-sol ekseninde görüntüyü fonksiyonel kaydırma işlemi 
clear all;
A=imread ('D:\dersler\BMOK-I\kodlar\Safari_RGB.jpg');
sat=size(A)(1)
sut=size(A)(2)
shfact=100;
orj=A;

for i=1:sat
for j=1:sut
k=floor( i + shfact*j/sut);
l=floor( j + shfact*sin(pi*i/sat));
%  if l<=sut
  B(k,l,:)=orj(i,j,:);
%  end
end
end

imwrite(B,'D:\dersler\BMOK-I\kodlar\ders3_4.jpg');