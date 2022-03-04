#include <stdlib.h>
#include "be-utility.h"

void clear_screen(void) {
  #if defined(_WIN32) || defined(_WIN64)
  system("cls");
  #else
  system("clear");
  #endif
}
