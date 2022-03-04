#include <stdio.h>

int main() {
  /* scanf() */
  // For char array data will only capture up to the first
  // whitespace character.
  // Can limit number of chars of char array data.
  // Newlines are part of the input stream.
  // Subsequent `scanf()` capture the remainder of the stream.
  char phrase[20];
  puts("Enter a phrase:");
  scanf("%s", phrase);
  printf("You entered '%s'.\n", phrase);
  puts("Enter another phrase:");
  scanf("%20s", phrase);  // Limiting to 20 chars.
  printf("You entered '%s'.\n", phrase);

  /* fgets() */
  // Does not terminate capture of the input stream at the
  // first whitespace character, unlike `scanf()`.
  // Newlines are also part of the input stream.
  char sentence[25];
  puts("Type in a sentence:");
  // Limit of `fgets()` set to char array length, i.e., 25.
  fgets(sentence, 25, stdin);
  printf("You typed '%s'.", sentence);
}
