all: square

square: main.o IOcoef.o is_equal.o solving_functions.o test.o my_assert.o colour.o
	g++ main.o IOcoef.o is_equal.o solving_functions.o test.o my_assert.o colour.o -o square -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr && ./square

debug: main.o my_assert.o
	g++ -DDEBUG main.o IOcoef.cpp is_equal.cpp solving_functions.cpp test.cpp my_assert.o colour.cpp -o debug && ./debug

test: IOcoef.o is_equal.o solving_functions.o test.o my_assert.o colour.o
	g++ main.cpp IOcoef.o is_equal.o solving_functions.o test.o my_assert.o colour.o -o test -DTEST && ./test

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

colour.o: colour.cpp
	g++ -c colour.cpp

clean:
	rm -rf *.o square test debug
