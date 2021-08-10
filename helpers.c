#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

float* copy_floats(const float arr[], size_t size) {
  float* result = malloc(size * sizeof(float));
  memcpy(result, arr, size * sizeof(float));
  return result;
}

float* generate_sinewave(const float hz, const float freq, const float amp, const size_t size) {
  float* sinewave = malloc(size * sizeof(float));
  for (size_t i = 0; i < size; i++)
    sinewave[i] = amp * sin(TAU * freq * i / hz);
  return sinewave;
}
