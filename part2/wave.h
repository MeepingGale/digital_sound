#ifndef wave_hpp
#define wave_hpp

#include <cstdlib>
#include <iostream>
#include <cmath>

#include "SoundSamples.h"
using namespace std;
class Wave {
private:
    string name;
public:
    Wave(string name) {
        this->name = name;
    }
    
    SoundSamples* generateSamples(float frequency, float samplerate, float duration);
    
    virtual float generateFunction(float time) = 0;
};

class SineWave : public Wave {
private:
    string name;
public:
    SineWave(string name):Wave(name){
        }
    float generateFunction(float time);
};

class SquareWave : public Wave {
private:
    string name;
public:
    SquareWave(string name):Wave(name){
        }
    float generateFunction(float time);
};

class TriangleWave : public Wave {
private:
    string name;
public:
    TriangleWave(string name):Wave(name){
        }
    float generateFunction(float time);
};

class SawtoothWave : public Wave {
private:
    string name;
public:
    SawtoothWave(string name):Wave(name){
        }
    float generateFunction(float time);
};

#endif
