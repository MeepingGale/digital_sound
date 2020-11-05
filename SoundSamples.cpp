#include <cstdlib>
#include <iostream>

// 1a
class SoundSamples {
  public:
    // 1b
    float* sequence_of_samples;
    int sample_len;
    float sample_rate;
    
    // 1c
    SoundSamples() {
        sequence_of_samples = new float[0];
        sample_len = 0;
        sample_rate = 8000;
    }
    
    // 1d
    SoundSamples(float* samples, int sample_len, float sample_rate) {
        this->sequence_of_samples = new float[sample_len];
        for(int i = 0; i < sample_len; i++)
            this->sequence_of_samples[i] = samples[i];
        this->sample_len = sample_len;
        this->sample_rate = sample_rate;
    }
    
    // 1e
    SoundSamples(int sample_len, float sample_rate) {
        sequence_of_samples = new float[sample_len];
        for(int i = 0; i < sample_len; i++)
            this->sequence_of_samples[i] = 0;
        this->sample_len = sample_len;
        this->sample_rate = sample_rate;
    }
    
    // 1g
    SoundSamples(const SoundSamples &s) {
        this->sequence_of_samples = new float[s.sample_len];
        for(int i = 0; i < s.sample_len; i++)
            this->sequence_of_samples[i] = s.sequence_of_samples[i];
        this->sample_len = s.sample_len;
        this->sample_rate = s.sample_rate;
    }
    
    // 1f
    float getSampleRate() {
        return sample_rate;
    }
    
    // 1h
    void operator= (const SoundSamples &s ) {
        sequence_of_samples = new float[s.sample_len];
        for(int i = 0; i < s.sample_len; i++)
            this->sequence_of_samples[i] = s.sequence_of_samples[i];
        sample_len = s.sample_len;
        sample_rate = s.sample_rate;
    }
    
    // 1i
    int getSampleLen() {
        return sample_len;
    }
    
    // 1j
    float &operator[] (int i) {
        return this->sequence_of_samples[i];
    }
    
    // 1k
    SoundSamples operator+ (const SoundSamples& s) {
        SoundSamples samples;
        // TODO
        return samples;
    }
    
};
