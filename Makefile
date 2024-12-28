	
c: c.exe
	./c.exe

c.exe: strflib.o test.o filehandlinglib.o userStruct.o
	gcc -o c strflib.o test.o main.c filehandlinglib.o userStruct.o

strflib.o:
	gcc -c strflib.c

filehandlinglib.o:
	gcc -c filehandlinglib.c

test.o:
	gcc -c test.c

userStruct.o:
	gcc -c userStruct.c

remove:
	rm c.exe strflib.o test.o filehandlinglib.o