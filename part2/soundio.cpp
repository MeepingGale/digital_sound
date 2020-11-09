#include <cstring>
#include <fstream>

#include "soundio.h"

using namespace std;

     void SoundIO::OutputSound(SoundSamples *samples, string filename){
        ofstream MyFile(filename);
        
        for(int i = 0; i < samples->getSampleRate(); i++)
            MyFile << samples->sequence_of_samples[i] << endl;

        // Close the file
        MyFile.close();
    }
