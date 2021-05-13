rsa:	example1.o rsa.o
	gcc example1.o rsa.o -o rsa

rsa.o:	rsa.c 
	gcc -c rsa.c

example1.o: example1.c
	gcc -c example1.c

clean:
	rm *.o rsa
