#include <stdlib.h>
#include <math.h>
#include "helpers.h"

void dft(float res[], float ims[], const size_t size) {
  // Taking these arrays as input and the argument arrays as output
  const float* in_res = copy_floats(res, size);
  const float* in_ims = copy_floats(ims, size);

  for (size_t k = 0; k < size; k++) {
    res[k] = 0;
    ims[k] = 0;
    for (size_t n = 0; n < size; n++) {
      float a = TAU * k * n / (float)size;
      res[k] += in_res[n] * cos(a);
      ims[k] -= in_ims[n] * sin(a);
    }
  }

  free(in_res);
  free(in_ims);
}
