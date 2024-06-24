#include <iostream>
#include <fstream>
#include <fftw3.h>
#include "source/Fresnel_integrals_PRESTO.h"
#include "source/Fresnel_for_vector.h"
#include "source/template_generator.h"
#include "source/padding_and_fft.h"

using namespace std;


int main(){
	struct sample{
		float real;
		float imag;
	};
	double x=10.0,y,z;
	double *SS;
	double *ZZ;
	vector<double> Res1;
	Res1=fresnl(x);
	fftw_complex fft[50];
//	cout << Res1[0] << endl;
//	cout << Res1[1] << endl;
	int i, size=100;
	vector<double> Inpt;
	vector<double> Res;
	vector<double> Final_filtr, Final_filti;
	for(i=0; i<size; i++){
		Inpt.push_back(i*0.1);
	}
	Fresnel_for_vector Fresnel(Inpt);
	 Fresnel.compute_fresnel();
	Res=Fresnel.FrC;

	ofstream outfile("FrC_100.txt");
	for(i=0; i<Res.size(); i++){	
		outfile << Res[i] << endl;
	}
	outfile.close();
	double width=30.0;
	vector<double> q, temp_real, temp_imag, real_padding, imag_padding;
	ofstream outfile1("Filter_30.txt");
	template_generator template1(width);
	template1.template_calc();	
	temp_real=template1.final_tempr;
	temp_imag=template1.final_tempi;
	q=template1.q;
	for(i=0;i<temp_real.size(); i++){
		outfile1 << to_string(q[i])+" "+to_string(temp_real[i])+" "+to_string(temp_imag[i]) << endl;
	}
	outfile1.close();
	padding_and_fft filter_final(temp_real, temp_imag);
	filter_final.do_padding();
	real_padding=filter_final.in_real;
	imag_padding=filter_final.in_imag;
	ofstream outfile2("Filter_padding_30.txt");
	for(i=0;i<real_padding.size(); i++){
                outfile2 << to_string(q[i])+" "+to_string(real_padding[i])+" "+to_string(imag_padding[i]) << endl;
        }
	outfile2.close();

	filter_final.do_fft();
	ofstream outfile3("Filter_padding_fft_30.txt");
        for(i=0;i<filter_final.out_real.size(); i++){
                outfile3 << to_string(q[i])+" "+to_string(filter_final.out_real[i])+" "+to_string(filter_final.out_imag[i]) << endl;
        }
        outfile3.close();


	
}
