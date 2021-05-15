rsa:	example1.o rsa.o
	gcc -lm example1.o rsa.o -o rsa

rsa.o:	rsa.c 
	gcc -c rsa.c -lm

example1.o: example1.c
	gcc -lm -c example1.c

clean:
	rm *.o rsa
