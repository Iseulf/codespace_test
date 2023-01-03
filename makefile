main:main.cpp ./bin/funs.o
	g++ main.cpp ./bin/funs.o -o ./bin/main -g -Wall
./bin/funs.o:funs.cpp
	g++ -c funs.cpp -o ./bin/funs.o -g -Wall

clean:
	@rm -rf ./bin/main ./bin/funs.o