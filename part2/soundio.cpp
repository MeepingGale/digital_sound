#include <cstring>
#include <fstream>

#include "SoundSamples.h"
#include "soundio.h"

using namespace std;

class SoundIO {
 public:
    void OutputSound(SoundSamples *samples, string filename) {
        ofstream MyFile(filename);
        
        for(int i = 0; i < samples->sample_len; i++)
        MyFile << *(samples->sequence_of_samples + i);

        // Close the file
        MyFile.close();
    }
};

int main() {
    return 0;
}
