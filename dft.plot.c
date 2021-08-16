#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dft.h"
#include "helpers.h"

int main() {
  // samples: 8192
  // sample_rate: 48000
  // sinewave_frequency: 440
  // frequency_resolution: sample_rate / samples
  //     = 48000 / 8192 = 5 + 55 / 64 = 5.859375
  // plotted_peak: 75
  // corresponding_frequency: plotted_peak * frequency_resolution
  //    = 75 * 48000 / 8192 = 439 + 29 / 64 = 439.453125
  // Close enough
  size_t size = 8192;
  float* sine_440 = generate_sinewave(48000, 440, 1, size);
  float* sine_cpy = calloc(size, sizeof(float));
  
  dft(sine_440, sine_cpy, size);

  for (size_t i = 0; i < size; i++)
    printf("%ld %20f\n", i, sine_440[i]);

  free(sine_440);
  free(sine_cpy);
  return 0;
}
