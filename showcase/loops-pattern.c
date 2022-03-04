#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n;
  printf("Enter an integer (1-9): ");
  scanf("%d", &n);
  putchar('\n');

  int max;
  int col;
  int limit = n + (n - 1);
  for(max = -n; max <= n; max++) {
    if(max != 0 && max != -1) {
      int a_max = abs(max);
      int digit = n;
      for(col = 1; col <= limit; col++) {
        printf("%d ", digit);

        if(col >= limit - (n - a_max)) {
          digit++;
        } else if(digit > a_max) {
          digit--;
        }
      }
      putchar('\n');
    }
  }
  putchar('\n');

  return(EXIT_SUCCESS);
}
