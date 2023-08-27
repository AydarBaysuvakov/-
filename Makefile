all: square

square: main.o IOcoef.o is_equal.o solving_functions.o test.o my_assert.o
	g++ main.o IOcoef.o is_equal.o solving_functions.o test.o my_assert.o -o square && ./square

main.o: main.cpp
	g++ -c main.cpp

IOcoef.o: IOcoef.cpp
	g++ -c IOcoef.cpp

is_equal.o: is_equal.cpp
	g++ -c is_equal.cpp

solving_functions.o: solving_functions.cpp
	g++ -c solving_functions.cpp

test.o: test.cpp
	g++ -c test.cpp

my_assert.o: my_assert.cpp
	g++ -c my_assert.cpp

clean:
	rm -rf *.o square
