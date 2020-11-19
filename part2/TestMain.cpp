#include <cstdio>
#include <iostream>
#include <cstring>

#include "SoundSamples.h"
#include "wave.h"
#include "soundio.h"

using namespace std;

bool cond;

void clear() {
#ifdef __linux__
    system("clear");
#endif
    
#ifdef __unix__
    system("clear");
#endif
    
#ifdef __FreeBSD__
    system("clear");
#endif
    
#ifdef _WIN32
    system("cls");
#endif
    
//#ifdef __APPLE__
//    system("clear");
//#endif
}

float pianoKeytoHertz(float keyNumber) {
    return (pow(2, (keyNumber - 49.0) / 12.0) * 440);
}

int main(int argc, char* argv[]) {
    clear();
    int wave_type = 0;
    float delay, attenuation, atime, alevel, dtime, slevel, rtime;
    string filename;
    float sample_rate = 8000;
    
    do {
        while(wave_type > 4 || wave_type <= 0) {
            cout << "Please enter a value 1-4" << endl;
            cout << "Enter a type of wave!" << endl;
            cout << "1. Sine" << endl;
            cout << "2. Square" << endl;
            cout << "3. Triangle" << endl;
            cout << "4. Saw" << endl;
            cin >> wave_type;
            
            clear();
            
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                continue;
            }
        }
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the delay." << endl;
        cin >> delay;
        clear();
        
        if(delay >= 0) {
            cond = cin.fail();
            cin.clear();
            cin.ignore();
        } else {
            cout << "Valid values for a delay is any number greater or equal to zero." << endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the attenuation." << endl;
        cin >> attenuation;
        clear();
        
        if(attenuation >= 0) {
            cond = cin.fail();
            cin.clear();
            cin.ignore();
        } else {
            cout << "Valid values for an attenuation is any number greater or equal to zero." << endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the atime." << endl;
        cin >> atime;
        clear();
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the alevel." << endl;
        cin >> alevel;
        clear();
        
        if((alevel <= 1 && alevel > 0) || cin.fail()) {
            cond = cin.fail();
            cin.clear();
            cin.ignore();
        } else {
            cout << "alevel cannot be greater than 1 and must be more than 0" << endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the dtime." << endl;
        cin >> dtime;
        clear();
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the slevel." << endl;
        cin >> slevel;
        clear();
        
        if((slevel <= 1 && slevel > 0) || cin.fail()) {
            cond = cin.fail();
            cin.clear();
            cin.ignore();
        } else {
            cout << "slevel cannot be greater than 1 and must be more than 0" << endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the rtime." << endl;
        cin >> rtime;
        clear();
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    if(atime + dtime + rtime > sample_rate){
        cout << "Sum of atime, dtime, rtime is more than than the total sample time." << endl;
        return 0;
    }
    cond = true;
    
    cout << "Enter the filename." << endl;
    cin >> filename;
    clear();
    
    float note = 0;
    
    Wave *w;
    
    switch(wave_type) {
        case 1:
            // Sine
            w = new SineWave("MySineWave");
            break;
        case 2:
            // Square
            w = new SquareWave("MySquareWave");
            break;
        case 3:
            // Triangle
            w = new TriangleWave("MyTriangleWave");
            break;
        case 4:
            // Saw
            w = new SawtoothWave("MySawWave");
            break;
        default:
            cout << "Invalid Wave Type!" << endl;
            cout << "For <wave type>:" << endl;
            cout << "1. Sine" << endl;
            cout << "2. Square" << endl;
            cout << "3. Triangle" << endl;
            cout << "4. Saw" << endl;
            return 1;
    }
    
    SoundSamples *samples2 = w->generateSilence(sample_rate, 0.25);
    cout << "Enter the note. (Positive Number)" << endl;
    cout << "Enter a negative number to terminate!" << endl;
    SoundSamples finalResult;
    SoundIO *printer;
    while(note >= 0) {
        do {
//            cout << "Enter the note. (Positive Number)" << endl;
//            cout << "Enter a negative number to terminate!" << endl;
            cin >> note;
            clear();
            
            cond = cin.fail();
            cin.clear();
            cin.ignore();
            
            if(cond && note >= 0)
                break;
        } while(cond);
        cond = true;
        if(note >= 0){
        SoundSamples *samples = w->generateSamples(pianoKeytoHertz(note), sample_rate, 1);
        samples->adsr(atime, alevel, dtime, slevel, rtime);
        samples->reverb2(delay, attenuation);
        SoundSamples result = (*samples) + (*samples2);
        finalResult = finalResult + result;
        }
    }
    printer->OutputSound(&finalResult, filename);

    return 0;
}
