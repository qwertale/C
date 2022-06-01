program should have compiled as;
	gcc -o proje proje.c
program should have executed as;
	proje.exe 5 5 5 5 5 
program's arguments is as follows;

1: proje.exe // program's name
2: first matris's row
3: first matris's column
4: second matris's row
5: second matris's column
6: number of threads

the program takes the matris elements from two text files, and the text file's names must have names as

	matris1.txt  matris2.txt

Colum and rows must be bigger then 0 and lower than MATRIX_DIMENSIONS
First matrises column lenght and second matrise row lenght must be same for calculation
The thread number must be same with first matrises column lenght and second matrises row lenght for calculation

If you want to change the matrix dimensions you can simple change the MATRIX_DIMENSIONS in 8. line
MATRIX_SIZE must be bigger then "rows*columns"
you can simple change the threads capacity by changeing THREAD_NUM 

Kamil Fatih Pehlivan 17060291 

Öğrettiğiniz herşey için teşekkürler hocam :)