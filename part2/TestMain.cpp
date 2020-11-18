#include <cstdio>
#include <iostream>
#include <cstring>

#include "wave.h"
#include "soundio.h"

using namespace std;

bool cond;

float pianoKeytoHertz(float keyNumber){
    return (pow(2, (keyNumber-49.0)/12.0)* 440);
}

int main(int argc, char* argv[]) {
    
    int wave_type = 0;
    float delay, attenuation, atime, alevel, dtime, slevel, rtime;
    string filename;
    float sample_rate = 8000;
    
    do {
        while(wave_type > 4 || wave_type <= 0) {
            cout << "Enter a type of wave!" << endl;
            cout << "1. Sine" << endl;
            cout << "2. Square" << endl;
            cout << "3. Triangle" << endl;
            cout << "4. Saw" << endl;
            cin >> wave_type;
            
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                continue;
            }
            cout<<"Please enter a value 1-4"<<endl;
        }
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the delay." << endl;
        cin >> delay;
        
        if(delay >= 0){
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        }else{
            cout<<"Valid values for a delay is any number greater or equal to zero."<<endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the attenuation." << endl;
        cin >> attenuation;
        
        if(attenuation >= 0){
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        }else{
            cout<<"Valid values for an attenuation is any number greater or equal to zero."<<endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the atime." << endl;
        cin >> atime;
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the alevel." << endl;
        cin >> alevel;
        
        if(alevel <= 1 && alevel > 0){
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        }else{
            cout<<"alevel cannot be greater than 1 and must be more than 0"<<endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the dtime." << endl;
        cin >> dtime;
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the slevel." << endl;
        cin >> slevel;
        
        if(slevel <= 1 && slevel > 0){
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        }else{
            cout<<"slevel cannot be greater than 1 and must be more than 0"<<endl;
        }
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the rtime." << endl;
        cin >> rtime;
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    if(atime + dtime + rtime > sample_rate){
        cout << "Sum of atime, dtime, rtime is more than than the total sample time."<< endl;
    }
    cond = true;
    
    cout << "Enter the filename." << endl;
    cin >> filename;
    
    return 0;
}
