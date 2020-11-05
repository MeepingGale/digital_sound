#include <cstring>

#include "wave.h"

using namespace std;

class Wave {
  public:
    string name;
    Wave(string name) {
        this->name = name;
    }
    
    virtual float generateFunction(float time);
};

class SineWave : public Wave {
    float generateFunction(float time) {
        return 0;
    }
};

class SquareWave : public Wave {
    float generateFunction(float time) {
        return 0;
    }
};

class TriangleWave : public Wave {
    float generateFunction(float time) {
        return 0;
    }
};

class SawtoothWave : public Wave {
    float generateFunction(float time) {
        return 0;
    }
};

int main() {
    return 0;
}
