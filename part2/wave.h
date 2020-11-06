#ifndef wave_hpp
#define wave_hpp

#include <stdio.h>

#include "soundsamples.cpp"

SoundSamples* generateSamples(float frequency, float samplerate, float duration);

float generateFunction(float time);

#endif
