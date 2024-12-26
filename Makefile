c: run
	rm c.exe strflib.o test.o filehandlinglib.o
	
run: c.exe
	./c.exe

c.exe: strflib.o test.o filehandlinglib.o
	gcc -o c strflib.o test.o main.c filehandlinglib.o

strflib.o:
	gcc -c strflib.c

filehandlinglib.o:
	gcc -c filehandlinglib.c

test.o:
	gcc -c test.c
remove:
	rm c.exe strflib.o test.o filehandlinglib.o