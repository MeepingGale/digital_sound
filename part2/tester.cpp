
#include <cstdlib>
#include <iostream>

using namespace std;
float* reverb2(float delay, float attenuation, int len, float samples[], float samplerate){
    float* result = new float[len];
    int sdelay = (samplerate * delay);
    for(int i = 0; i < len; i++){
        if(i -sdelay < 0)
            result[i] = samples[i];
        else
            result[i] = samples[i] + result[i - sdelay]*attenuation;
    }
    return result;
}

int main(){
    float floatArray[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float *result = reverb2(1, 1, 10, floatArray, 5);
    
    for (int i = 0; i < 10; i++) {
        cout << result[i] <<endl;
    }
}
