#include "wave.h"

using namespace std;

float SineWave::generateFunction(float time) {
        return sin(2.0 * M_PI * time);
    }

float SquareWave::generateFunction(float time) {
        return 2*(2*floor(time)-floor(2* time))+1;
    }

float TriangleWave::generateFunction(float time) {
        return 2*(fabs(2*((time)-floor(0.5 + (time)))))-1;
    }

float SawtoothWave::generateFunction(float time) {
        return 2*((time)-floor(0.5 + (time)));
    }

SoundSamples* Wave:: generateSamples(float frequency, float samplerate, float duration){
    int size =duration* samplerate;
    float* samples = new float[size];
    for (int i = 0; i < size; i++) {
        samples[i] = generateFunction(i *frequency/samplerate);
    }
    SoundSamples* result = new SoundSamples(samples ,duration* samplerate, samplerate);
    return result;
}

