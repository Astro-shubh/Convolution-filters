#include "template_generator.h"

using namespace std;
template_generator::template_generator(double drift1){drift=drift1;}
void template_generator::width_array(){for(j=-1*drift ;j < drift+1 ; j++){q.push_back(j);}}
void template_generator::left_edge_array(){for(j=-1*drift;j<drift; j++){Z.push_back(j+drift/2.0);}}
void template_generator::right_edge_array(){for(j=-1*drift;j<drift; j++){Y.push_back(j-drift/2.0);}}
void template_generator::compute_SC(){
	Fresnel_for_vector Fresnel(Y);
	Fresnel.compute_fresnel();
	Sy=Fresnel.FrS;
	Cy=Fresnel.FrC;
	Fresnel_for_vector Fresnel1(Z);
	Fresnel1.compute_fresnel();
	Sz=Fresnel1.FrS;
	Cz=Fresnel1.FrC;
}
void template_generator::template_calc1(){
	for(i=0;i<Y.size();i++){temp1.push_back(pi*Y[i]*Y[i]/drift);}
}

void template_generator::template_calc2(){
        for(i=0;i<Y.size();i++){final_tempr.push_back(cos(temp1[i])*(Sz[i]-Sy[i]));}
	for(i=0;i<Y.size();i++){final_tempi.push_back(sin(temp1[i])*(Cz[i]-Cy[i]));}
}
void template_generator::template_calc(){
	width_array();
	left_edge_array();
	right_edge_array();
	compute_SC();
	template_calc1();
	template_calc2();
}

