#ifndef PADDING_AND_FFT_H
#define PADDING_AND_FFT_H

#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
#include <fftw3.h>

class padding_and_fft{
        public:
                std::vector<double> out_real, out_imag;
		std::vector<double> real_padding, imag_padding;
		std::vector<double> in_real, in_imag;
                padding_and_fft(std::vector<double> temp_real, std::vector<double> temp_imag, int fil_len);
                void do_padding();
                void do_fft();
        private:
                int i, num_rot, temp_size, fil_len;
                const int fft_len=1024;
                double a;
};

#endif
