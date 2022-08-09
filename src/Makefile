CC    = gcc
CFLAGS       = -fPIC -g -Wall -Wextra -I. -Ied25519-donna -Icryptonite
LDFLAGS      = -shared

TARGET_LIB = libcryptonite.so
SOURCES = $(wildcard cryptonite/*.c)
HEADER = $(wildcard cryptonite/*.h)
OBJECTS = $(SOURCES:.c=.o)

TARGET = cardano
SRCS = $(wildcard *.c)
DEPS = $(wildcard *.h)
OBJS = $(SRCS:.c=.o)


.PHONY: all

all: $(TARGET_LIB) $(TARGET)

$(TARGET_LIB): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJS)

ed25519.o: ed25519.c 
	gcc -m64 -O3 -Ied25519-donna -Icryptonite -I. -Wall -Wextra -g -c  -o ed25519.o ed25519.c

encrypted.o: encrypted.c 
	gcc -m64 -O3  -Ied25519-donna -Icryptonite -Wall -Wextra -g -c -o encrypted.o encrypted.c

cardano: ed25519.o encrypted.o 
	gcc -m64 -Wall -Ied25519-donna -Wextra -o cardano ed25519.o encrypted.o -L. -lcryptonite -g -lssl -lcrypto main.c

.PHONY: clean
clean:
	-rm -f *.o */*.o *.so
	-rm -f cardano* bench*
