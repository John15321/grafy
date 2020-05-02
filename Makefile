CXXFLAGS=-Iinc -Wall -pedantic -g -std=c++0x

__start__: grafy
	./grafy

grafy: obj/main.o obj/lists.o obj/arrays.o obj/paths.o 
	g++ -Wall -pedantic -std=c++0x -o grafy obj/main.o obj/lists.o obj/arrays.o obj/paths.o 

obj/main.o: scr/main.cpp inc/graphs.hh inc/lists.hh inc/arrays.hh
	g++ -c $(CXXFLAGS) -o obj/main.o scr/main.cpp

obj/lists.o: scr/lists.cpp inc/lists.hh inc/graphs.hh
	g++ -c $(CXXFLAGS) -o obj/lists.o scr/lists.cpp

obj/arrays.o: scr/arrays.cpp inc/arrays.hh inc/graphs.hh
	g++ -c $(CXXFLAGS) -o obj/arrays.o scr/arrays.cpp

obj/paths.o: scr/paths.cpp inc/paths.hh inc/arrays.hh inc/lists.hh
	g++ -c $(CXXFLAGS) -o obj/paths.o scr/paths.cpp

clean:
	rm -f obj/*.o grafy