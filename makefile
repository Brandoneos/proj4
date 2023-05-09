build:
	g++ -g -Wall -std=c++2a main.cpp -o program.out

test:
	g++ -Wall -std=c++2a tests.cpp -o tests.out -lgtest -lgtest_main -lpthread

run:
	./program.out

runtest:
	./tests.out

clean:
	rm -f program.out
	rm -f tests.out

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./program.out
