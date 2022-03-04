/**
 * OUTPUT TECHNIQUES
 */
#include <stdio.h>

int main() {
  /* puts() */
  // Outputs data to the screen with a newline.
  puts("This line ends with a newline.");

  /* printf() */
  // Allows for escape sequences, placeholders.
  // Does not tag a newline on the end by default.
  int digit = 3;
  char alpha = 'Q';
  char name[12] = "William";
  printf("Number %d\tLetter %c\nName: %s\n", digit, alpha, name);

  // Can even format data...
  float pi = 3.1415927;
  printf("Pi to 3 decimal places is: %.3f.\n", pi);

  /* putchar() */
  // Outputs a single character, even a single escape sequence.
  putchar('m');
  putchar('\n');
  putchar('N');

  return(0);
}
