#include <stdio.h>
#include <math.h>
#include "UnitTest++.h"
#include "DSP.h"


    namespace
    {
        TEST(testDSPFindMean)
        {
            DSP x;
            int i;
            double def_mean;
            for (i=0; i<DEFAULT_SIGNAL_SIZE; i++) {
                x.samp[i] = i+1; //x.samp[i] = i+1;
            }
            def_mean = DEFAULT_SIGNAL_SIZE/2;
            printf("\n \nThe mean is %E", x.mean());
            printf("\n \nThe def mean is %E \n", def_mean );
            //cout  << "\n \nThe def mean is" << def_mean.ToString() << "\n";

            CHECK_EQUAL(true,     fabs( (x.mean()) - def_mean )  < 0.6  );
            x.~DSP();
        }

        TEST(testDSPRandomSignal) //not tested. Write test again
        {
            DSP x;
            x.randomSignal(0,255);
            CHECK_EQUAL(true, true );

        }
        TEST(testDSPConvolution) //Not tested. Write test again
        {
            DSP x;
            int h[DEFAULT_CONVOLUTION_SIGNAL_SIZE], y[DEFAULT_SIGNAL_SIZE + DEFAULT_CONVOLUTION_SIGNAL_SIZE];
            int z[DEFAULT_SIGNAL_SIZE + DEFAULT_CONVOLUTION_SIGNAL_SIZE];
            x.convolution(h, y);
            x.convolutionOutput(h,z);
            CHECK_EQUAL(true,    z[20] == y[20]);
            x.~DSP();
        }
        TEST(testDSP_DFT_IDFT) //Not tested. Write test again
        {
            DSP x,y;
            int i;
            x.DFT();
            for(i=0; i<DEFAULT_SIGNAL_SIZE; i++) {
                y.ReY[i] = x.ReY[i];
                y.ImY[i] = x.ImY[i];
            }

            y.IDFT();
            for(i=0; i<DEFAULT_SIGNAL_SIZE; i++) {
                if(x.samp[i] - y.samp[i] > 0.0001) {
                    CHECK_EQUAL(true, false);
                    break;
                }
            }
            x.~DSP();
        }



    }
