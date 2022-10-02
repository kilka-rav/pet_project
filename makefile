all:
	g++ -c main.cpp
	g++ -c draw.cpp
	g++ main.o draw.o -lsfml-graphics -lsfml-window -lsfml-system -o run

clean:
	rm -rf *.o run