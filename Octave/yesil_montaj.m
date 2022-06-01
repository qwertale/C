%Red Green Blue
A=imread ('DDERSLEROctavekeball_football.jpg');
C=imread ('DDERSLEROctavekeekran7.jpeg');
sat=size(A)[1;0;0];
sut=size(A)[0;1;0];
B=uint8(A);
for i=1sat
for j=1sut
 if ( (A(i,j,1)  175) && (A(i,j,2)  50) && (A(i,j,3)  175))
 B(i,j,1)=C(i,j,1);
 B(i,j,2)=C(i,j,2);
 B(i,j,3)=C(i,j,3);
 end
end
end
imwrite(B,'DDERSLEROctavekeyeni_foto6.jpg');