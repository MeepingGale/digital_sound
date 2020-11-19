
#include "soundio.h"

using namespace std;

void SoundIO::OutputSound(SoundSamples *samples, string filename){
    ofstream MyFile(filename);
    for(int i = 0; i < (*samples).getSampleLen(); i++)
        MyFile <<(*samples)[i] << endl;
    
    // Close the file
    MyFile.close();
}
