#ifndef TEMPLATE_GENERATOR_H
#define TEMPLATE_GENERATOR_H

#include <iostream>
#include <vector>
#include <math.h>
#include "Fresnel_for_vector.h"

class template_generator{
        public:
		template_generator(double drift);
                std::vector<double> q, temp1, temp2r, temp2i, final_tempr, final_tempi;
                void template_calc();
        private:
                int i, size;
		double drift, j, pi=3.1415926535;
		std::vector<double> Y, Z;
		std::vector<double> Sy, Sz, Cy, Cz;
		void width_array();
		void left_edge_array();
		void right_edge_array();
		void compute_SC();
		void template_calc1();
		void template_calc2();
};
#endif
