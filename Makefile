all: compile link

compile:
	g++ -Isrc/include -I. -c main.cpp

link:
	g++ main.o -o ttt ico.res -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system