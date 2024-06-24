#include "padding_and_fft.h"

using namespace std;

padding_and_fft::padding_and_fft(vector<double> temp_real, vector<double> temp_imag){
	in_real=temp_real;
	in_imag=temp_imag;
}

void padding_and_fft::do_padding(){
	cout << "started padding" << endl;
	temp_size=in_real.size();
	num_rot=(int) (fil_len/2.0 - temp_size/2.0); 
	for (i=0; i<fft_len-temp_size; i++){
		in_real.push_back(0.0);
		in_imag.push_back(0.0);
	}
	cout << "started rotation" << endl;
	rotate(in_real.begin(), in_real.begin() + fft_len - num_rot, in_real.end());
	rotate(in_imag.begin(), in_imag.begin() + fft_len - num_rot, in_imag.end());
	cout << "Done padding and rotation" << endl;
}

void padding_and_fft::do_fft(){
	fftw_complex in_complex[fft_len]; 
	fftw_complex out_complex[fft_len];
	for(i=0; i<fft_len; i++){
		in_complex[i][0] = in_real[i];
		in_complex[i][1] = in_imag[i];
	}
	in_real.clear();
	in_imag.clear();
	cout << "Moved in to complex" << endl;
	fftw_plan p;
	cout << "Plan defined" << endl;
	p = fftw_plan_dft_1d(fft_len, in_complex, out_complex, FFTW_FORWARD, FFTW_ESTIMATE);
	cout << "Plan made" << endl;
	fftw_execute(p);
	cout << "Done FFT" << endl;
	fftw_destroy_plan(p);
//	in_complex.clear();
	cout << "Done FFT" << endl;
        for(i=0; i<fft_len; i++){
                out_real.push_back(out_complex[i][0]);
                out_imag.push_back(out_complex[i][1]);
        }
	fftw_cleanup();
}


	
