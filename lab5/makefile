output: main.o menu.o tablica.o komorka.o
	g++ main.o menu.o tablica.o komorka.o -o output

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

tablica.o: tablica.cpp
	g++ -c tablica.cpp

komorka.o: komorka.cpp
	g++ -c komorka.cpp

clean: 
	rm *.o output
