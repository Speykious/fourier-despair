#include <stdio.h>
#include <stdlib.h>
#include "dft.h"
#include "helpers.h"

int main() {
  size_t size = 1000;
  float* sine_440 = generate_sinewave(44100, 440, 1, size);
  float* sine_cpy = copy_floats(sine_440, size);
  
  dft(sine_440, sine_cpy, size);

  for (size_t i = 0; i < size; i++)
    printf("%ld%10f\n", i, sine_440[i]);

  return 0;
}
