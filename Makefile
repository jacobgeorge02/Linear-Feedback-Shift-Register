CC = g++
CFLAGS = -std=c++14 -Wall -Werror -pedantic
PM_OBJECTS = FibLFSR.o PhotoMagic.o
T_OBJECTS = FibLFSR.o test.o
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
LIB = -lboost_unit_test_framework

all: PhotoMagic test

PhotoMagic: $(PM_OBJECTS)
	$(CC) $(CFLAGS) -o PhotoMagic $(PM_OBJECTS) $(LIBS)

test: $(T_OBJECTS)
	$(CC) $(CFLAGS) -o test $(T_OBJECTS) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $< 

clean:
	rm test PhotoMagic *.o