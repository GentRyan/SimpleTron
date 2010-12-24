# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all: SimpleTron

SimpleTron: main.o sml.o input_from_file.o
	$(CC) main.o sml.o input_from_file.o -o ../simpletron && rm *o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
sml.o: sml.cpp
	$(CC) $(CFLAGS) sml.cpp

input_from_file.o: input_from_file.cpp
	$(CC) $(CFLAGS) input_from_file.cpp

clean:
	rm -rf *o SimpleTron