#ifndef __FOURIER_HELPERS__
#define __FOURIER_HELPERS__

#include <stdlib.h>

#define TAU 6.283185307179586476925286766559
#define PI  3.141592653589793238462643383279

float* copy_floats(const float arr[], size_t size);
float* generate_sinewave(const float hz, const float freq, const float amp, const size_t size);
float* generate_cosinewave(const float hz, const float freq, const float amp, const size_t size);

#endif
