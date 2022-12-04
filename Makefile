all: main

main:
	@g++ -o test Main.cpp -lGL -lglut -lGLU
	@./test
