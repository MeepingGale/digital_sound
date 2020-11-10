#include <cstdio>
#include <iostream>
#include <cstring>

#include "wave.h"
#include "soundio.h"

using namespace std;

//main <wave type (1, 2, 3, or 4) for the type of file> <a sample rate> <frequency> <duration>  <file name>
int main(int argc, char* argv[]) {
    if(argc < 6 || argc > 6) {
        cout << "Usage: [./main <wave type> <sample_rate> <frequency> <duration> <file_name>]" << endl;
        cout << "For <wave type>:" << endl;
        cout << "1. Sine" << endl;
        cout << "2. Square" << endl;
        cout << "3. Triangle" << endl;
        cout << "4. Saw" << endl;
    }
    
    Wave *w;
    
    switch(stoi(argv[1])) {
        case 1:
            // Sine
        {
           w = new SineWave("MySineWave");
            break;
        }
        case 2:
            // Square
        {
           w = new SquareWave("MySquareWave");
            break;
        }
        case 3:
            // Triangle
        {
            w = new TriangleWave("MyTriangleWave");
            break;
        }
        case 4:
            // Saw
        {
            w = new SawtoothWave("MySawWave");
            break;
        }
        default:
            cout << "Invalid Wave Type!" << endl;
            cout << "For <wave type>:" << endl;
            cout << "1. Sine" << endl;
            cout << "2. Square" << endl;
            cout << "3. Triangle" << endl;
            cout << "4. Saw" << endl;
            return 1;
    }
    
    SoundSamples *s = w->generateSamples(atof(argv[3]),atof(argv[2]),atof(argv[4]));
    SoundIO *printer;
    printer->OutputSound(s, argv[5]);
    
    return 0;
}
