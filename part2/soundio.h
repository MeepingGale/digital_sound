#ifndef soundio_h
#define soundio_h

#include "SoundSamples.h"

#include <stdio.h>

using namespace std;

class SoundIO {
 public:
    static void OutputSound(SoundSamples *samples, string filename);

};
#endif
