#include <stdlib.h>
#include <string.h>

float* copy_floats(const float arr[], size_t size) {
  float* result = malloc(size * sizeof(float));
  memcpy(result, arr, size * sizeof(float));
  return result;
}
