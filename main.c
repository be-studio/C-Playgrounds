#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

char **files;
char *active_dir;

int get_file_list(const char *);
void show_file_list(int);
int is_listed_directory(const char *);
int get_file_choice(void);
int is_directory(const char *);
char *generate_command(const char *);
void clear_screen(void);

int main(void) {
  char *filename;
  active_dir = ".";
  char command[500] = "";
  int input_mode = 1;

  do {
    files = (char **)malloc(sizeof(char *) * 500);
    
    clear_screen();
    int file_count = get_file_list(active_dir);
    show_file_list(file_count);
    filename = *(files + get_file_choice());
    if(is_directory(filename)) {
      *(filename + strlen(filename) - 1) = '\0';
      active_dir = filename;
    } else {
      input_mode = 0;
    }
  } while(input_mode);
  
  strcpy(command, generate_command(filename));
  clear_screen();
  system(command);

  return(0);
}

int get_file_list(const char *dir) {
  struct dirent *de;
  DIR *dr = opendir(dir);

  char *file;
  char path[128] = "";
  int filename_length;
  int i = 0;

  while((de = readdir(dr)) != NULL) {
    file = de->d_name;
    filename_length = strlen(file);
    if(strcmp(dir, ".") != 0) {
      strcpy(path, active_dir);
      strcat(path, "/");
      strcat(path, file);
    } else {
      strcpy(path, file);
    }

    struct stat buffer;
    stat(path, &buffer);
    if(S_ISDIR(buffer.st_mode) && is_listed_directory(file)) {
      *(file + filename_length) = '*';
      *(file + filename_length + 1) = '\0';
      *(files + i) = file;
      i++;
    } else {
      char file_end[3] = {
        *(file + filename_length - 2),
        *(file + filename_length - 1),
        '\0'
      };

      if(strcmp(file_end, ".c") == 0) {
        *(file + filename_length - 2) = '\0';
        *(files + i) = file;
        i++;
      }
    }
  }
  closedir(dr);

  return(i);
}

void show_file_list(int count) {
  int i;
  for(i = 0; i < count; i++) {
    printf("%d. %s\n", i, *(files + i));
  }
}

int is_listed_directory(const char *file) {
  char *unlisted_dirs[] = {
    ".",
    "..",
    ".cache",
    ".ccls-cache",
    ".git"
  };
  int i;

  for(i = 0; i < 5; i++) {
    if(strcmp(file, *(unlisted_dirs + i)) == 0) {
      return(0);
    }
  }

  return(1);
}

int get_file_choice(void) {
  int choice;
  printf("Enter number of file to run: ");
  scanf("%d", &choice);
  return(choice);
}

int is_directory(const char *filename) {
  if(*(filename + strlen(filename) - 1) == '*') {
    return(1);
  }
  return(0);
}

char *generate_command(const char *filename) {
  char command[500] = "";
  char path[128] = "";
  
  if(strcmp(active_dir, ".") != 0) {
    strcpy(path, active_dir);
    strcat(path, "/");
    strcat(path, filename);
  } else {
    strcpy(path, filename);
  }
  
  char a[] = "gcc -o ";
  char b[] = ".out ";
  char c[] = ".c && ./";
  char d[] = ".out";

  strcat(command, a);
  strcat(command, path);
  strcat(command, b);
  strcat(command, path);
  strcat(command, c);
  strcat(command, path);
  strcat(command, d);

  return(command);
}

void clear_screen(void) {
  #if defined(_WIN32) || defined(_WIN64)
  system("cls");
  #else
  system("clear");
  #endif
}
