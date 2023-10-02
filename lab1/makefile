output: main.o menu.o tablice.o
	g++ main.o menu.o tablice.o -o output

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

tablice.o: tablice.cpp
	g++ -c tablice.cpp

clean: 
	rm *.o output
