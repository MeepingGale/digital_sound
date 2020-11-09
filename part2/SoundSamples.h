#ifndef SoundSamples_h
#define SoundSamples_h
#include <cstdlib>
#include <iostream>

using namespace std;

class SoundSamples {
  private:
    // 1b
    float* sequence_of_samples;
    int sample_len;
    float sample_rate;

public:
    SoundSamples() {
        sequence_of_samples = new float[0];
        sample_len = 0;
        sample_rate = 8000;
    }
    
    //d
    SoundSamples(float* samples, int sample_len, float sample_rate);
    
    //1e
    SoundSamples(int sample_len, float sample_rate);
    
    //1f
    float getSampleRate() ;
    
    // 1g
    SoundSamples(const SoundSamples &s);
    
    //1h
    void operator= (const SoundSamples &s );
    
    // 1i
    int getSampleLen();
    
    //1j
    float& operator[] (int i);
    
    //1k
    SoundSamples operator+ (const SoundSamples& s);
};

#endif /* SoundSamples_h */
