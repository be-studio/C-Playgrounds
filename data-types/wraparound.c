#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  unsigned int u = UINT_MAX;
  printf("UINT_MAX\t%u\n", u);

  u++;
  printf("UINT_MAX + 1\t%u\n", u);

  u++;
  printf("UINT_MAX + 2\t%u\n", u);

  u--;
  u--;
  printf("UINT_MAX\t%u\n", u);

  return(EXIT_SUCCESS);
}
