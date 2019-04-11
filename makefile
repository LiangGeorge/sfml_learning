all: playground.cpp
	g++ -c playground.cpp
	g++ playground.cpp -o output -lsfml-graphics -lsfml-window -lsfml-system

run:
	./output 
