#include "Fresnel_for_vector.h"

using namespace std;
void Fresnel_for_vector::compute_fresnel(){
	int i, size=input_vector.size();
	for(i=0; i<size; i++){
		vector<double> SC;
		SC=fresnl(input_vector[i]);
		FrC.push_back(SC[0]);
		FrS.push_back(SC[1]);
	}
}

Fresnel_for_vector::Fresnel_for_vector(vector<double> inputvector){input_vector=inputvector;}

