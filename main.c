#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(void) {
  char filename[50];
  char command[500] = "";

  system("cls");

  struct dirent *de;
  DIR *dr = opendir(".");

  puts("C PLAYGROUNDS COMPILER");

  char *file;
  int filename_length;

  while((de = readdir(dr)) != NULL) {
    file = de->d_name;
    filename_length = strlen(file);
    char file_end[3] = {*(file + filename_length - 2), *(file + filename_length - 1), '\0'};
    // printf("%s\n", file_end);

    if(strcmp(file_end, ".c") == 0) {
      printf("%s\n", de->d_name);
    }
  }
  closedir(dr);


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
