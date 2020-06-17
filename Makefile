objects = submarine.o main.o

all: $(objects)
	gcc $(objects) -o program.exe

%.o: %.c submarine.h
	gcc -c $< -o $@

clean:
	rm -rf *.o *.exe

rebuild: clean all

run: program.exe
	program.exe b1.txt b2.txt game.txt