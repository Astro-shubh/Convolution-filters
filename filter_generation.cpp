#include <iostream>
#include <fstream>
#include <fftw3.h>
#include <vector>
#include "source/Fresnel_integrals_PRESTO.h"
#include "source/Fresnel_for_vector.h"
#include "source/template_generator.h"
#include "source/padding_and_fft.h"

using namespace std;

int main(){
	int i,j,k, numfilters=43;
	double width,d2;
	vector<double> filter_widths, temp_real, temp_imag;
	struct sample{
                float real;
                float imag;
                };


//   Define the filter widths
	for(i=0; i<numfilters; i++){
		if(i==0){
			filter_widths.push_back(1.0);
		}
		else{
			filter_widths.push_back(i*5.0);
		}
	}

//   Filestreams to store the generated filters
	ofstream wf("padding_fft_results.dat", ios::out | ios::binary);
	ofstream outfile("padding_fft_results.txt");

//   Start generating the filters for earch width in the filter_widthsi
	cout << numfilters << endl;
	for(i=1; i<numfilters; i++){
		width=filter_widths[i];
		cout << "computing template for width "+to_string(width) << endl;
//  generate template for the width
		template_generator template1(width);
		template1.template_calc();

// Paddign and FFT
		temp_real=template1.final_tempr;
		temp_imag=template1.final_tempi;
		template1.final_tempr.clear();
		template1.final_tempi.clear();
		padding_and_fft filter_final(temp_real, temp_imag);
// Padding of the template
		filter_final.do_padding();
// FFT of the padded template
		filter_final.do_fft();
// Store the filter in the structure of real and imaginary floats
		j=filter_final.out_real.size();
		sample filter_samples[j];
		for(k=0; k<j; k++){
                	filter_samples[k].real=filter_final.out_real[k];
                	filter_samples[k].imag=filter_final.out_imag[k];
        	}
// Write the filter in the designated binary file
		for(k=0; k<j; k++){
                	wf.write((char *) &filter_samples[k], sizeof(sample));
        	}
        	
	}
	wf.close();
}






