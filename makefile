FLAGS := -g -std=c++20 -pedantic -Wall -Wextra -Werror -Wshadow -Wconversion -Wunreachable-code
MAIN := main
UTILS := function
EXECUTABLE := prog
OBJ := object

all: main

main:  $(UTILS).cpp $(wildcard $(MAIN).cpp)
	g++ $(FLAGS) -c $(MAIN).cpp -o $(OBJ).o
	g++ $(OBJ).o -o $(EXECUTABLE)

rm:
	rm -rf *.o $(EXECUTABLE)
