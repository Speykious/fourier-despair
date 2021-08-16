#include <stdlib.h>
#include <math.h>
#include "helpers.h"

void dft(float res[], float ims[], const size_t size) {
  // Taking these arrays as input and the argument arrays as output
  float* in_res = copy_floats(res, size);
  float* in_ims = copy_floats(ims, size);

  for (size_t k = 0; k < size; k++) {
    res[k] = 0;
    ims[k] = 0;

    float angle_unit = TAU * k / (float)size;
    for (size_t i = 0; i < size; i++) {
      float a = i * angle_unit;
      res[k] +=  in_res[i] * cos(a) + in_ims[i] * sin(a);
      ims[k] += -in_res[i] * sin(a) + in_ims[i] * cos(a);
    }
  }

  free(in_res);
  free(in_ims);
}

void dft_with_tables(float res[], float ims[], const size_t size) {
  // Taking these arrays as input and the argument arrays as output
  float* in_res = copy_floats(res, size);
  float* in_ims = copy_floats(ims, size);

  float* costable = malloc(size * sizeof(float));
  float* sintable = malloc(size * sizeof(float));
  for (size_t k = 0; k < size; k++) {
    res[k] = 0;
    ims[k] = 0;

    float angle_unit = TAU * k / (float)size;
    for (size_t i = 0; i < size; i++) {
      float a = i * angle_unit;
      costable[i] += cos(a);
      sintable[i] += sin(a);
    }

    for (size_t i = 0; i < size; i++) {
      res[k] +=  in_res[i] * costable[i] + in_ims[i] * sintable[i];
      ims[k] += -in_res[i] * sintable[i] + in_ims[i] * costable[i];
    }
  }

  free(costable);
  free(sintable);
  free(in_res);
  free(in_ims);
}
