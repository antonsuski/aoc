.phony: all clean test

1-2: 1-2.cxx
	g++ 1-2.cxx --std=c++23 -o 1-2

test: 1-2 test
	./1-2 test

clean:
	rm 1-2.o 1-2

all: clean 1-2 test

