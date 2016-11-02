enigma: main.o Rotor.o Plugboard.o Reflector.o
	g++ -g -Wall main.o Rotor.o Plugboard.o Reflector.o -o enigma

main.o: main.cpp Rotor.h Plugboard.h
	g++ -g -Wall -c main.cpp

Rotor.o: Rotor.cpp Rotor.h
	g++ -g -Wall -c Rotor.cpp

Plugboard.o: Plugboard.cpp Plugboard.h
	g++ -g -Wall -c Plugboard.cpp

Reflector.o: Reflector.cpp Reflector.h
	g++ -g -Wall -c Reflector.cpp
