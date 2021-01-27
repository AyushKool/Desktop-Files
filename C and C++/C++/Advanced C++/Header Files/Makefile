output: main.o Log.o
	g++ main.o Log.o -o output

main.o: main.cpp
	g++ -c main.cpp
	
Log.o: Log.cpp Log.h
	g++ -c Log.cpp

clean:
	rm *.o output