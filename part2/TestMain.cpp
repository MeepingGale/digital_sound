#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

bool cond;

int main(int argc, char* argv[]) {
    
    int wave_type = 0;
    float delay, attenuation, atime, alevel, dtime, slevel, rtime;
    string filename;
    
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
        }
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the delay." << endl;
        cin >> delay;
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the attenuation." << endl;
        cin >> attenuation;
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
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
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
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
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    do {
        cout << "Enter the rtime." << endl;
        cin >> rtime;
        
        cond = cin.fail();
        cin.clear();
        cin.ignore();
        
    } while(cond);
    
    cond = true;
    
    cout << "Enter the filename." << endl;
    cin >> filename;
    
    return 0;
}
