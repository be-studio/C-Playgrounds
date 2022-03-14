/**
 * BE C PLAYGROUND
 * 
 * Complex Numbers
 *
 * @file complex.c
 * @author Eric L.
 * @copyright (C)2022, BE Studio
 */
#include <stdio.h>
#include <complex.h>  // Provides `complex` and `I` macros.

int main() {
  // Checking that i^2 = -1...
  double complex imagine = I;
  // Need to convert `cpow()` result to real number.
  printf("%.1f\n", creal(cpow(imagine, 2)));

  // Complex number arithmetic...
  float complex i = 3.0 + 4.0 * I;
  float complex j = 2.0 + 5.0 * I;
  float complex sum = i + j;
  // Use `creal()` and `cimag()` to extract parts.
  printf("%.1f + %.1fi\n", creal(sum), cimag(sum));
}
