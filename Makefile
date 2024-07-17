go: filter_generation filter_generation.cpp source/Fresnel_for_vector.cpp source/Fresnel_integrals_PRESTO.cpp source/padding_and_fft.cpp source/template_generator.cpp
	g++ -o filter_generation filter_generation.cpp source/Fresnel_for_vector.cpp source/Fresnel_integrals_PRESTO.cpp source/padding_and_fft.cpp source/template_generator.cpp -l fftw3
