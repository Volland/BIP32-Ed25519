CFLAGS = -Wall -Wextra -Ied25519-donna -g
LDFLAGS = -lssl -lcrypto


default: cardano

ed25519.o: ed25519.c 
	gcc -m64 -O3 -Ied25519-donna -I. -Wall -Wextra -g -c  -o ed25519.o ed25519.c

encrypted.o: encrypted.c 
	gcc -m64 -O3  -Ied25519-donna -Wall -Wextra -g -c -o encrypted.o encrypted.c

cardano: ed25519.o encrypted.o
	gcc -m64 -Wall -Ied25519-donna -Wextra -o cardano ed25519.o encrypted.o -g -lssl -lcrypto main.c

clean:
	-rm -f *.o */*.o
	-rm -f cardano*
