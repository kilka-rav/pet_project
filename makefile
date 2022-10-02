all:
	g++ -c main.cpp
	g++ -c draw.cpp
	g++ main.o draw.o -lsfml-graphics -lsfml-window -lsfml-system -o run

ir:
	clang++ main.cpp -S -emit-llvm -o lloyd.ll

clean:
	rm -rf *.o run lloyd.ll
