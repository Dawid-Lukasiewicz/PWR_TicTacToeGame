CPPFLAGS= -c -Iinc -Wall -pedantic -std=c++17

_start_: game

game: obj/main.o obj/Board.o
	g++ -g -o game obj/main.o obj/Board.o

obj/main.o: src/main.cpp inc/Board.hpp
	g++ ${CPPFLAGS} -o obj/main.o main.cpp

obj/Board.o: inc/Board src/Board.cpp
	g++ ${CPPFLAGS} -o obj/Board.o src/Board.cpp

clean:
	rm -f obj/*.o game