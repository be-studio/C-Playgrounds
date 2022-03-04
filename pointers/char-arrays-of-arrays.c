#include <stdio.h>
#include <stdlib.h>

void alloc(char **, int);
void check_alloc(void *);
void get_items(char **, int);
void display(char **, int);
void free_mem(char **, int);

int main() {
  system("clear");

  char **items;
  int i, count;

  printf("How many items? ");
  scanf("%d", &count);

  items = (char **)malloc(sizeof(char *) * count);
  check_alloc(items);

  alloc(items, count);

  get_items(items, count);

  putchar('\n');

  display(items, count);

  putchar('\n');

  free_mem(items, count);

  return(EXIT_SUCCESS);
}

void alloc(char **buffer, int count) {
  int i;
  for(i = 0; i < count; i++) {
    *(buffer + i) = (char *)calloc(100, sizeof(char));
    check_alloc(buffer);
  }
}

void check_alloc(void *buffer) {
  if(buffer == NULL) {
    puts("Unable to allocate memory. Program will now exit.");

    exit(EXIT_FAILURE);
  }
}

void get_items(char **items, int count) {
  int i;
  for(i = 0; i < count; i++) {
    printf("Type in item %d: ", i + 1);
    scanf("%s", *(items + i));
  }
}

void display(char **buffer, int count) {
  int i;
  for(i = 0; i < count; i++) {
    printf("%s\n", *(buffer + i));
  }
}

void free_mem(char **buffer, int count) {
  int i;
  for(i = 0; i < count; i++) {
    free(*(buffer + i));
  }
  free(buffer);
}
