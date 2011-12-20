IDIR=./include
CC=g++
CFLAGS=-I$(IDIR)
OBJ = json.o test.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

json: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm -f *.o

.PHONY: clean
clean:
	rm -f *.o *.out json