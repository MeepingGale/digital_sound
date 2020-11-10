#include "SoundSamples.h"

SoundSamples::SoundSamples(float* samples, int sample_len, float sample_rate) {
    this->sequence_of_samples = new float[sample_len];
    
    for(int i = 0; i < sample_len; i++)
        this->sequence_of_samples[i] = samples[i];
    
    this->sample_len = sample_len;
    this->sample_rate = sample_rate;
}

SoundSamples::SoundSamples(int sample_len, float sample_rate) {        this->sequence_of_samples = new float[sample_len];
    
    for(int i = 0; i < sample_len; i++)
        this->sequence_of_samples[i] = 0;
    
    this->sample_len = sample_len;
    this->sample_rate = sample_rate;
}

SoundSamples::SoundSamples(const SoundSamples &s) {
    this->sequence_of_samples = new float[s.sample_len];
    
    for(int i = 0; i < s.sample_len; i++)
        this->sequence_of_samples[i] = s.sequence_of_samples[i];
    
    this->sample_len = s.sample_len;
    this->sample_rate = s.sample_rate;
}

float SoundSamples::getSampleRate() {
    return sample_rate;
}

int SoundSamples::getSampleLen() {
    return sample_len;
}

float& SoundSamples::operator[] (int i) {
    return sequence_of_samples[i];
}

void SoundSamples::operator= (const SoundSamples &s ) {
    this->sequence_of_samples = new float[s.sample_len];
    
    for(int i = 0; i < s.sample_len; i++)
        this->sequence_of_samples[i] = s.sequence_of_samples[i];
    
    this->sample_len = s.sample_len;
    this->sample_rate = s.sample_rate;
}

SoundSamples SoundSamples::operator+ (const SoundSamples& s) {
    int len = this->sample_len + s.sample_len;
    int j = 0;
    
    SoundSamples *results = new SoundSamples(len, this->sample_rate);
    results->sequence_of_samples = new float[len];
    
    for(int i = 0; i < this->sample_len; i++)
        results->sequence_of_samples[i] = this->sequence_of_samples[i];
    
    for(int i = this->sample_len; i < len; i++)
        results->sequence_of_samples[i] = s.sequence_of_samples[j++];
    
    return *results;
}

