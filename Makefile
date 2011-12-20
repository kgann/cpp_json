IDIR=./include
CC=g++
CFLAGS=-I$(IDIR)
OBJ = json.o test.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

json: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o *.out json