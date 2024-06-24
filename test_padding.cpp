#include <iostream>
#include <fstream>
#include <fftw3.h>
#include "source/padding_and_fft.h"

using namespace std;
int main(){
	        struct sample{
                float real;
                float imag;
        	};
        int i,j, size=2;
        float x,y,z;
        vector<double> in_real, in_imag;
        fftw_complex in_array[size], out_array[size];
        for(i=0;i<size;i++){
                in_array[i][0] = cos(i*0.1);
		in_real.push_back(cos(i*0.1));
                in_array[i][1] = 0.0;
		in_imag.push_back(0.0);
        }
	padding_and_fft filter(in_real, in_imag);
	filter.do_padding();
	filter.do_fft();
	j=filter.out_real.size();
	sample filter_samples[j];
	for(i=0; i<j; i++){
		filter_samples[i].real=filter.out_real[i];
		filter_samples[i].imag=filter.out_imag[i];
	}
	ofstream wf("padding_fft_results.dat", ios::out | ios::binary);
	ofstream outfile("padding_fft_results.txt");
	for(i=0; i<j; i++){
		wf.write((char *) &filter_samples[i], sizeof(sample));
		outfile << to_string(filter_samples[i].real)+" "+to_string(filter_samples[i].imag) << endl;
	}
	wf.close();
	outfile.close();
}
