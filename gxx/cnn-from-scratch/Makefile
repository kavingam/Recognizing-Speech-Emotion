CC = gcc
CFLAGS = -Wall -Iinclude -O2
OBJ = src/cnn.o src/layers.o src/utils.o src/activation.o

all: cnn

cnn: main.c $(OBJ)
	$(CC) $(CFLAGS) -o cnn main.c $(OBJ) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o cnn
