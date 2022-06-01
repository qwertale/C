%  3x3 konvol�syon i�in padding fonksiyonu
clear all;
A=[ 1 2 3 3 5;  6 7 8 9 10; 11 12 13 14 15 ];
sat=size(A)*[1;0]
sut=size(A)*[0;1]

for i=1:sat
for j=1:sut
 B(i+1,j+1)=A(i,j); %A matrisi, B matrisinin merkezine ta��n�r
 	if i==1
	B(1,j+1)=A(1,j );  % A matrisinin 1. sat�r� B matrisinin 1. sat�r�na kopyalan�r
	end
	
	if i==sat
	B(sat+2,j+1)=A(sat,j );  % A matrisinin son sat�r� B matrisinin son sat�r�na kopyalan�r
	end
	
	if j==1
	B(i+1,1 )=A(i,1 );  % A matrisinin 1. s�tunu, B matrisinin 1. s�tununa kopyalan�r
	end
	if j==sut
	B(i+1,sut+2 )=A(i,sut); % A matrisinin son s�tunu, B matrisinin son s�tununa kopyalan�r
	end
end
end
B(1,1 )=A(1,1 );
B(sat+2,1 )=A(sat,1 );
B(1,sut+2 )=A(1,sut );
B(sat+2,sut+2 )=A(sat,sut );
