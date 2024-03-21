CC=gcc
CFLAGS=-I. -lm
LIBS=-ltestu01 -lprobdist -lmylib
OBJ1=smallcrush.o
OBJ2=bigcrush.o

all: smallcrush bigcrush

smallcrush: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

bigcrush: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o smallcrush bigcrush
