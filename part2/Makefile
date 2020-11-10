all: parta

parta: main
	
main: main.o SoundSamples.o wave.o soundio.o
	g++ -o main main.o SoundSamples.o wave.o soundio.o -lm
	
main.o: main.cpp
	g++ -c main.cpp
	
SoundSamples.o: SoundSamples.h SoundSamples.cpp
	g++ -c SoundSamples.cpp
	
wave.o: wave.h wave.cpp
	g++ -c wave.cpp

soundio.o: soundio.h soundio.cpp
	g++ -c soundio.cpp

clean:
	rm -f main *.o