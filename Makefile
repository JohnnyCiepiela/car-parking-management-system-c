execute: main.o Vehicle.o
	g++ main.o Vehicle.o -o execute

main.o: main.cpp Vehicle.h
	g++ -c main.cpp Vehicle.h

Vehicle.o: Vehicle.cpp Vehicle.h
	g++ -c Vehicle.cpp Vehicle.h

clean:
	rm *.o execute
