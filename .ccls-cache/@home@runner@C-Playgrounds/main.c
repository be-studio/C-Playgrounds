#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *filename;
  char command[128];
  
  printf("Enter filename without extension: ");
  scanf("%s", filename);

  char a[] = "gcc -o ";
  char b[] = " ";
  char c[] = ".c && ./";

  strcat(command, a);
  strcat(command, filename);
  strcat(command, b);
  strcat(command, filename);
  strcat(command, c);
  strcat(command, filename);

  system(command);

  return(0);
}
