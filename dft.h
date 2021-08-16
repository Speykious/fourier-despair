#ifndef __FOURIER_DFT__
#define __FOURIER_DFT__

#include <stdlib.h>

void dft(float res[], float ims[], const size_t size);
void dft_with_tables(float res[], float ims[], const size_t size);

#endif
