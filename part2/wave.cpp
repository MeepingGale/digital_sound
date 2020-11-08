#include "wave.h"

using namespace std;

class SineWave : public Wave {
    Wave::float generateFunction(float time) {
        return sin(2.0 * M_PI * time);
    }
};

class SquareWave : public Wave {
    Wave::float generateFunction(float time) {
        return 2*(2*floor(time)-floor(2* time))+1;
    }
};

class TriangleWave : public Wave {
    Wave::float generateFunction(float time) {
        return 2*(fabs(2*((time)-floor(0.5 + (time)))))-1;
    }
};

class SawtoothWave : public Wave {
    Wave::float generateFunction(float time) {
        return 2*((time)-floor(0.5 + (time)));
    }
};
