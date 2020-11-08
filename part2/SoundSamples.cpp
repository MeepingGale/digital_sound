#include "SoundSamples.h"
    
    // 1d
SoundSamples::SoundSamples(float* samples, int sample_len, float sample_rate) {
        this->sequence_of_samples = new float[sample_len];
        for(int i = 0; i < sample_len; i++)
            this->sequence_of_samples[i] = samples[i];
        this->sample_len = sample_len;
        this->sample_rate = sample_rate;
    }
    
    // 1e
SoundSamples::SoundSamples(int sample_len, int sample_rate) {
        this->sequence_of_samples = new float[sample_len];
        for(int i = 0; i < sample_len; i++)
            this->sequence_of_samples[i] = 0;
        this->sample_len = sample_len;
        this->sample_rate = sample_rate;
    }
    
    // 1g
SoundSamples::SoundSamples(const SoundSamples &s) {
        this->sequence_of_samples = new float[s.sample_len];
        for(int i = 0; i < s.sample_len; i++)
            this->sequence_of_samples[i] = s.sequence_of_samples[i];
        this->sample_len = s.sample_len;
        this->sample_rate = s.sample_rate;
    }
    
    // 1f
SoundSamples::int getSampleRate() {
        return sample_rate;
    }
    
    // 1h
SoundSamples::void operator= (const SoundSamples &s ) {
        this->sequence_of_samples = new float[s.sample_len];
        for(int i = 0; i < s.sample_len; i++)
            this->sequence_of_samples[i] = s.sequence_of_samples[i];
        this->sample_len = s.sample_len;
        this->sample_rate = s.sample_rate;
    }
    
    // 1i
SoundSamples::int getSampleLen() {
        return sample_len;
    }
    
    // 1j
SoundSamples::float &operator[] (int i) {
        return this->sequence_of_samples[i];
    }
    
    // 1k
SoundSamples:: SoundSamples operator+ (const SoundSamples& s) {
        SoundSamples samples;
        // TODO
        return samples;
    }
    
