all: parta partb

parta: main

partb: main2b
	
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

main2b: TestMain.o wave.o soundio.o
	g++ -o main2b TestMain.o SoundSamples.o wave.o soundio.o

TestMain.o: TestMain.cpp
	g++ -c TestMain.cpp

clean:
	rm -f main main2b *.o