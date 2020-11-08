#ifndef wave_hpp
#define wave_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>

#include "SoundSamples.h"

class Wave {
private:
    string name;
public:
    Wave(string name) {
        this->name = name;
    }
    
    SoundSamples* generateSamples(float frequency, float samplerate, float duration);
    
    virtual float generateFunction(float time);
};

#endif
