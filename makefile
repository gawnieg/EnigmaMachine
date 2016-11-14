enigma: main.o Rotor.o Plugboard.o Reflector.o Enigma.o
	g++ -g -Wall main.o Rotor.o Plugboard.o Reflector.o Enigma.o -o enigma

main.o: main.cpp Rotor.h Plugboard.h
	g++ -g -Wall -std=c++11 -c main.cpp

Rotor.o: Rotor.cpp Rotor.h
	g++ -g -Wall -std=c++11 -c Rotor.cpp

Plugboard.o: Plugboard.cpp Plugboard.h
	g++ -g -Wall -std=c++11 -c Plugboard.cpp

Reflector.o: Reflector.cpp Reflector.h
	g++ -g -Wall -std=c++11 -c Reflector.cpp

Enigma.o: Enigma.cpp Enigma.h
	g++ -g -Wall -std=c++11 -c Enigma.cpp
