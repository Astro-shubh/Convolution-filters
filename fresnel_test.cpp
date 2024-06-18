#include <iostream>
#include <fstream>
#include <fftw3.h>
#include "source/Fresnel_integrals_PRESTO.h"
#include "source/Fresnel_for_vector.h"
#include "source/template_generator.h"

using namespace std;
int main(){
	double x=10.0,y,z;
	double *SS;
	double *ZZ;
	vector<double> Res1;
	Res1=fresnl(x);
	fftw_complex fft[30];
//	cout << Res1[0] << endl;
//	cout << Res1[1] << endl;
	int i, size=100;
	vector<double> Inpt;
	vector<double> Res;
	for(i=0; i<size; i++){
		Inpt.push_back(i*1.0);
	}
	Fresnel_for_vector Fresnel(Inpt);
	 Fresnel.compute_fresnel();
	Res=Fresnel.FrS;
//	for(i=0;i<size;i++){cout << Res[i] << endl;}
	double drift=30.0;
	template_generator template1(drift);
	template1.template_calc();
	ofstream outfile("results.txt");
	for(i=0; i<template1.q.size(); i++){ outfile << to_string(template1.q[i])+" "+to_string(template1.final_tempr[i])+" "+to_string(template1.final_tempi[i])+" "+to_string(sqrt(pow(template1.final_tempi[i],2)+pow(template1.final_tempr[i],2.0)))+" "+to_string(atan(template1.final_tempi[i]/template1.final_tempr[i])) << endl;}
	for(i=0; i<template1.q.size(); i++){ cout << template1.final_tempr[i] << endl;}
}

