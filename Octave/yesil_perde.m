%Red Green Blue
A=imread ('D:/DERSLER/Octaveke/top2.jpg');

sat=size(A)*[1;0;0];
sut=size(A)*[0;1;0];

B=uint8(A);

for i=1:sat
for j=1:sut
  if ( (A(i,j,1) < 175) &&   (A(i,j,3) < 175) && (A(i,j,2) > 50))
    B(i,j,1)=1;
    B(i,j,2)=1;
    B(i,j,3)=1;
  end
end
end

imwrite(B,'D:/DERSLER/Octaveke/yeni_top2.jpg');
