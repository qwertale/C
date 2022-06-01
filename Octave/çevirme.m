%rotation
clear all;
A=imread ('D:\dersler\BMOK-I\kodlar\Safari_RGB.jpg');
sat=size(A)*[1;0;0];
sut=size(A)*[0;1;0];
centx=sut/2;
centy=sat/2;

%for sayma=1:2
%alfa=sayma*pi/2;
alfa=-pi/18;
B=ones(sat,sut,3);
B=B.*255;
B=uint8(B);
    for i=1:sat
    for j=1:sut
    orj=A(i,j,:);
	  l=ceil(cos(alfa)*(j-centx)-sin(alfa)*(i-centy)+centx);
    k=ceil(sin(alfa)*(j-centx)+cos(alfa)*(i-centy)+centy);
         if ((k<=sat)&&(l<=sut))&&((k>=1)&&(l>=1))
        B(k,l,:)=uint8(orj);
        end 
    end
    end
%imshow(B);
%fname=sprintf('img%03d.jpg',sayma);
imwrite(B,'D:\dersler\BMOK-I\kodlar\ders3_3.jpg');
%end