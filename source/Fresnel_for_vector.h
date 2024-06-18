#ifndef FRESNEL_FOR_VECTOR_H
#define FRESNEL_FOR_VECTOR_H
#include <iostream>
#include <vector>
#include "Fresnel_integrals_PRESTO.h"

class Fresnel_for_vector{
        public:
                std::vector<double> input_vector;
		Fresnel_for_vector(std::vector<double> inputvector);
                std::vector<double> FrS, FrC;

                void compute_fresnel();
};

#endif
