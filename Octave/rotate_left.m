%rotation
clear all;
A=imread ('D:\dersler\BMOK-I\kodlar\Safari.jpg');

sat=size(A)*[1;0];
sut=size(A)*[0;1];
xo=50;

orj=A;
clear A;
for i=1:sat
for j=1:sut
  A(j,i)=orj(i,sut-j+1);
end
end


%imshow(B);
imwrite(A,'D:\dersler\BMOK-I\kodlar\ders4_6.jpg');
%end