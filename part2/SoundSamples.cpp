#include "SoundSamples.h"

SoundSamples::SoundSamples(float* samples, int sample_len, float sample_rate) {
    this->sequence_of_samples = new float[sample_len];
    
    for(int i = 0; i < sample_len; i++)
        this->sequence_of_samples[i] = samples[i];
    
    this->sample_len = sample_len;
    this->sample_rate = sample_rate;
}

SoundSamples::SoundSamples(int sample_len, float sample_rate) {
    this->sequence_of_samples = new float[sample_len];
    
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
    
    for(int i = 0; i < this->sample_len; i++)
        results->sequence_of_samples[i] = this->sequence_of_samples[i];
    
    for(int i = this->sample_len; i < len; i++)
        results->sequence_of_samples[i] = s.sequence_of_samples[j++];
    
    return *results;
}

void SoundSamples:: reverb2( float delay, float attenuation) {
    float *results = new float[this->sample_len];
    int sdelay = (this->sample_rate * delay);
    for(int i = 0; i < this->sample_len; i++){
        if(i -sdelay < 0)
            results[i] = this->sequence_of_samples[i];
        else
            results[i] = this->sequence_of_samples[i] + results[i - sdelay]*attenuation;
    }
    for(int i = 0; i < this->sample_len; i++){
        this->sequence_of_samples[i] = results[i];
    }
    delete[] results;
}

void SoundSamples:: adsr(float atime, float alevel, float dtime, float slevel, float rtime) {
    float *results = new float[this->sample_len];
    for(int i = 0; i < this->sample_len; i++){
        if(i < atime +1){
        results[i] = (alevel/atime)*i;
        }
        else if(i >= (atime + 1) && i < (atime + dtime +1))
            results[i] = ((alevel - slevel)/-dtime)*i + (alevel - ((alevel-slevel)/-dtime)*atime);
        else if(i >= this->sample_len - rtime&& i < this->sample_len)
            results[i] = (slevel/-rtime)*i + (0 - (slevel/-rtime)*(this->sample_len-1));
        else
            results[i] = slevel;
    }
    for(int i = 0; i < this->sample_len; i++){
        this->sequence_of_samples[i] *= results[i];
    }
    delete[] results;
}
