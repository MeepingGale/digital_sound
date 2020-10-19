void gensine(float frequency, float sampleRate, float duration);

void DTMF(float freq1, float freq2);

void phone_pad(char ch);

void make_silence(float sampleRate, float duration);

sound *gensine2( float hertz, float sample_rate, float duration);

sound *genDTMF2(char key, float sample_rate, float duration);

sound *genSilence(float sample_rate, float duration);

int outputSound( sound *s, FILE *f);
