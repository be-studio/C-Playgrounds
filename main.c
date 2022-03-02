#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char filename[50];
  char command[500] = "";

  system("clear");

  puts("C PLAYGROUNDS COMPILER");
  printf("Enter filename without extension: ");
  scanf("%s", filename);

  char a[] = "gcc -o ";
  char b[] = ".out ";
  char c[] = ".c && ./";
  char d[] = ".out";

  strcat(command, a);
  strcat(command, filename);
  strcat(command, b);
  strcat(command, filename);
  strcat(command, c);
  strcat(command, filename);
  strcat(command, d);

  system("clear");
  system(command);

  return(0);
}
