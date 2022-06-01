
%rotation
clear all;
A=imread ('D:\dersler\BMOK-I\kodlar\Safari.jpg');
sat=size(A)*[1;0]
sut=size(A)*[0;1]

alfa= pi/4;

orj=A;

for i=1:sat
for j=1:sut
  delta=(j-(sut/2))*sin(alfa)-(i-(sat/2))*cos(alfa);
  bx=ceil(j-2*delta*sin(alfa) );
  by=ceil(i+2*delta*cos(alfa));
  if (bx>0 && bx<=sut) && (by>0 && by<=sat)
  B(by,bx)=orj(i,j);
  end
end
end

%imshow(B)
imwrite(B,'D:\dersler\BMOK-I\kodlar\ders4_4.jpg');