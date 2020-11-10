#ifndef SoundSamples_h
#define SoundSamples_h

#include <cstdlib>
#include <iostream>

using namespace std;

class SoundSamples {
private:
    float* sequence_of_samples;
    int sample_len;
    float sample_rate;
    
public:
    SoundSamples() {
        sequence_of_samples = new float[0];
        sample_len = 0;
        sample_rate = 8000;
    }
    
    SoundSamples(float* samples, int sample_len, float sample_rate);
    
    SoundSamples(int sample_len, float sample_rate);
    
    float getSampleRate() ;
    
    SoundSamples(const SoundSamples &s);
    
    void operator= (const SoundSamples &s );
    
    int getSampleLen();
    
    float& operator[] (int i);
    
    SoundSamples operator+ (const SoundSamples& s);
};

#endif
