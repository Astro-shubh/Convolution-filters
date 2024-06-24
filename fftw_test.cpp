#include <iostream>
#include <fstream>
#include <fftw3.h>
#include <math.h>
#include <vector>
using namespace std;

int main(){
	int i,j, size=512;
	float x,y,z;
	vector<double> in_real, in_imag;
	fftw_complex in_array[size], out_array[size];
	for(i=0;i<size;i++){
		in_array[i][0] = cos(i*0.1);
		in_array[i][1] = 0.0;
	}
	cout << "starting plan" << endl;
	fftw_plan p = fftw_plan_dft_1d(size, in_array, out_array, FFTW_FORWARD, FFTW_ESTIMATE);
	cout << "plan prepared" << endl;
	fftw_execute(p);
	cout << "plan executed" << endl;
	fftw_destroy_plan(p);
	cout << "starting computing amplitude" << endl;
	ofstream outfile("result_fftw.txt");
	for(i=0; i<size; i++){
		outfile << sqrt(pow(out_array[i][0],2) + pow(out_array[i][1],2)) << endl;

	}
	cout << "Done computing amplitude" << endl;
}



