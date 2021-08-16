#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include "dft.h"
#include "helpers.h"

int main() {
  size_t size = 8192, repetitions = 10;
  clock_t beg, end, d, min_celta, max_celta, celta;
  double delta, min_delta, max_delta;



  // DFT Benchmark - Without trigonometric tables
  d = 0, min_celta = (clock_t)INT_MAX, max_celta = 0, celta = 0;
  for (size_t i = 0; i < repetitions; i++) {
    fprintf(stderr, "\x1b[2K\rTest n°%ld", i + 1);
    fflush(stderr);
    float* sine_440 = generate_sinewave(48000, 440, 1, size);
    float* sine_cpy = calloc(size, sizeof(float));
    beg = clock();
    dft(sine_440, sine_cpy, size);
    end = clock();
    d = end - beg;
    celta += d;
    if (d < min_celta) min_celta = d;
    if (d > max_celta) max_celta = d;
    free(sine_440);
    free(sine_cpy);
  }
  delta = (double)celta / CLOCKS_PER_SEC;
  min_delta = (double)min_celta / CLOCKS_PER_SEC;
  max_delta = (double)max_celta / CLOCKS_PER_SEC;
  printf(
    "\x1b[2K\r"
    "DFT Benchmark - Without trigonometric tables\n"
    "| Total time for %ld repetitions: %fs (%d clocks/s)\n"
    "| Average per repetition: %fs (%.2f clocks/s)\n"
    "| Extremes per repetition: [%fs (%d clocks/s), %fs (%d clocks/s)]\n\n",
    repetitions, delta, (int)celta,
    delta / (double)repetitions, (double)celta / repetitions,
    min_delta, (int)min_celta, max_delta, (int)max_celta
  );



  // DFT Benchmark - With trigonometric tables
  d = 0, min_celta = (clock_t)INT_MAX, max_celta = 0, celta = 0;
  for (size_t i = 0; i < repetitions; i++) {
    fprintf(stderr, "\x1b[2K\rTest n°%ld", i + 1);
    fflush(stderr);
    float* sine_440 = generate_sinewave(48000, 440, 1, size);
    float* sine_cpy = calloc(size, sizeof(float));
    beg = clock();
    dft_with_tables(sine_440, sine_cpy, size);
    end = clock();
    d = end - beg;
    celta += d;
    if (d < min_celta) min_celta = d;
    if (d > max_celta) max_celta = d;
    free(sine_440);
    free(sine_cpy);
  }
  delta = (double)celta / CLOCKS_PER_SEC;
  min_delta = (double)min_celta / CLOCKS_PER_SEC;
  max_delta = (double)max_celta / CLOCKS_PER_SEC;
  printf(
    "\x1b[2K\r"
    "DFT Benchmark - With trigonometric tables\n"
    "| Total time for %ld repetitions: %fs (%d clocks/s)\n"
    "| Average per repetition: %fs (%.2f clocks/s)\n"
    "| Extremes per repetition: [%fs (%d clocks/s), %fs (%d clocks/s)]\n",
    repetitions, delta, (int)celta,
    delta / (double)repetitions, (double)celta / repetitions,
    min_delta, (int)min_celta, max_delta, (int)max_celta
  );



  return 0;
}
