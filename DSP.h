
   #ifndef DSP_H_INCLUDED
   #define DSP_H_INCLUDED

   using namespace std;
    #define DEFAULT_SIGNAL_SIZE 512
    #define DEFAULT_FFT_SIZE 255
    #define DEFAULT_HISTOGRAM_SIZE 255
    #define DEFAULT_CONVOLUTION_SIGNAL_SIZE 20
    #define PI 3.14159265358979323846

class DSP
{
    private:
    public:
        int samp[DEFAULT_SIGNAL_SIZE];
        int ReY[DEFAULT_SIGNAL_SIZE/2], ImY[DEFAULT_SIGNAL_SIZE/2];
        DSP();
        void randomSignal(int , int);
        double mean();
        double SD();
        void convolution(int * , int *);
        void convolutionOutput(int * , int *);
        void DFT();
        void IDFT();
        virtual ~DSP();


};
   #endif // SENTENCE_H_INCLUDED
