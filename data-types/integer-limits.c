#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int main() {
  puts("INTEGER LIMITS");
  puts("Unsigned");
  printf("Char\t\t0 - %u\n", UCHAR_MAX);
  printf("Short\t\t0 - %u\n", USHRT_MAX);
  printf("Int\t\t0 - %u\n", UINT_MAX);
  printf("Int8\t\t0 - %u\n", UINT8_MAX);
  printf("Int16\t\t0 - %u\n", UINT16_MAX);
  printf("Int32\t\t0 - %u\n", UINT32_MAX);
  printf("Int64\t\t0 - %llu\n", UINT64_MAX);
  printf("Long\t\t0 - %lu\n", ULONG_MAX);
  printf("Long Long\t0 - %llu\n", ULLONG_MAX);

  putchar('\n');

  puts("Signed");
  printf("Char\t\t%d - %d\n", CHAR_MIN, CHAR_MAX);
  printf("Short\t\t%d - %d\n", SHRT_MIN, SHRT_MAX);
  printf("Int\t\t%d - %d\n", INT_MIN, INT_MAX);
  printf("Int8\t\t%d - %d\n", INT8_MIN, INT8_MAX);
  printf("Int16\t\t%d - %d\n", INT16_MIN, INT16_MAX);
  printf("Int32\t\t%d - %d\n", INT32_MIN, INT32_MAX);
  printf("Int64\t\t%lld - %lld\n", INT64_MIN, INT64_MAX);
  printf("Long\t\t%ld - %ld\n", LONG_MIN, LONG_MAX);
  printf("Long Long\t%lld - %lld\n", LLONG_MIN, LLONG_MAX);

  return(EXIT_SUCCESS);
}
