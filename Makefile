main: main.o funcs.o
	g++ --std=c++11 -o main main.o funcs.o

tests: tests.o funcs.o
	g++ --std=c++11 -o tests tests.o funcs.o

funcs.o: funcs.cpp profile.h network.h
	g++ --std=c++11 -c funcs.cpp
clean:
	rm -f main.o tests.o funcs.o