#include <stdio.h>
#include <math.h>
#include <random>
#include "DSP.h"
#include "UnitTest++.h"
#include <time.h>

using namespace std;
DSP::DSP()
{
    //ctor


}

void DSP::randomSignal(int min, int max) { //Generates signal from "min" to "max"
    int i;
    srand (time(NULL));
    for (i=0; i< DEFAULT_SIGNAL_SIZE; i++) {
        this->samp[i] = min + (max-min) * rand() / RAND_MAX;
        //printf("%d  ", this->samp[i]);
    }
}
double DSP::mean() {
    int i;
    long SUM = 0;
    double_t MEAN; //d;
    for (i=0; i<DEFAULT_SIGNAL_SIZE; i++) {
        SUM = SUM + this->samp[i];
        //MEAN = SUM/(i+1);
    }
    //printf("The SUM is %l", SUM);
    MEAN = SUM;
    //d = DEFAULT_SIGNAL_SIZE;
    return (MEAN/DEFAULT_SIGNAL_SIZE );
}

double DSP::SD() {

}

void DSP::convolution(int * H, int *Y) { //Uses output side algorithm from table 6-1
    int i, j;
    for (i=0; i< (DEFAULT_SIGNAL_SIZE + DEFAULT_CONVOLUTION_SIGNAL_SIZE); i++) {
        Y[i] = 0;
    }
    for (i=0; i< DEFAULT_SIGNAL_SIZE ; i++) {
        for (j=0; j< DEFAULT_CONVOLUTION_SIGNAL_SIZE; j++) {
            Y[i +j] = Y[i +j] + this->samp[i] * H[j];
        }
    }

}
void DSP::convolutionOutput(int * H, int *Y) { //Uses output side algorithm from table 6-2
    int i, j;
    for (i=0; i< (DEFAULT_SIGNAL_SIZE + DEFAULT_CONVOLUTION_SIGNAL_SIZE); i++) {
        Y[i] = 0;

        for (j=0; j< DEFAULT_CONVOLUTION_SIGNAL_SIZE; j++) {
            if ( (i-j) < 0 ) continue;
            if ( (i-j) > DEFAULT_SIGNAL_SIZE) continue;
            Y[i] = Y[i] + this->samp[i-j] * H[j];
        }

    }

}

void DSP::IDFT() {
    int i,k;

    for (k=0; k< DEFAULT_SIGNAL_SIZE/2; k++) {
        this->ReY[k] = this->ReY[k]/DEFAULT_SIGNAL_SIZE/2;
        this->ImY[k] = -this->ReY[k]/DEFAULT_SIGNAL_SIZE/2;
    }
    this->ReY[k] = this->ReY[k]/2;
    this->ImY[k] = this->ReY[k]/2;

    for (i=0; i< DEFAULT_SIGNAL_SIZE; i++) {
            this->samp[i] = 0;
    }

    for (k=0; k< DEFAULT_SIGNAL_SIZE/2; k++) {
        for (i=0; i< DEFAULT_SIGNAL_SIZE-1; i++) {
            this->samp[i] = this->samp[i] + this->ReY[k] * cos(2 * PI * k * i/DEFAULT_SIGNAL_SIZE);
            this->samp[i] = this->samp[i] + this->ImY[k] * sin(2 * PI * k * i/DEFAULT_SIGNAL_SIZE);
        }
    }
}
void DSP::DFT() {
    int i,k;
    for (k=0; k< DEFAULT_SIGNAL_SIZE/2; k++) {
        this->ReY[k] = 0;
        this->ImY[k] = 0;
    }

    for (k=0; k< DEFAULT_SIGNAL_SIZE/2; k++) {
        for (i=0; i< DEFAULT_SIGNAL_SIZE-1; i++) {
            this->ReY[k] = this->ReY[k] + this->samp[i] * cos(2 * PI * k * i/DEFAULT_SIGNAL_SIZE);
            this->ImY[k] = this->ImY[k] - this->samp[i] * sin(2 * PI * k * i/DEFAULT_SIGNAL_SIZE);
        }
    }
}
DSP::~DSP()
{
    //dtor
}

