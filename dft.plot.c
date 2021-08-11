#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dft.h"
#include "helpers.h"

int main() {
  size_t size = 8192;
  float* sine_440 = generate_sinewave(44100, 10000, 1, size);
  float* sine_cpy = calloc(size, sizeof(float));//copy_floats(sine_440, size);
  
  dft(sine_440, sine_cpy, size);

  for (size_t i = 0; i < size; i++)
    printf("%ld %20f\n", i, sine_440[i]);

  free(sine_440);
  free(sine_cpy);
  return 0;
}
