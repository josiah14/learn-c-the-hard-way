#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("ERROR: You need one argument.\n");
    // early program abortion due to error
    // use a non-zero return code to indicate error.
    return 1;
  }

  for (int i = 0; argv[1][i] != '\0'; i++) {
    char letter = argv[1][i];
    // to uppercase
    if (letter > 90) {
      letter = letter - 32;
    }

    switch (letter) {
    case 'a': // fall through
    case 'A':
      printf("%d: %d: 'A'\n", i, letter);
      break;
    case 'E':
      printf("%d: %d: 'E'\n", i, letter);
      break;
    case 'I':
      printf("%d: %d: 'I'\n", i, letter);
      break;
    case 'O':
      printf("%d: %d: 'O'\n", i, letter);
      break;
    case 'U':
      printf("%d: %d: 'U'\n", i, letter);
      break;
    case 'Y':
      // Y is only a vowel sometimes
      if (i > 2) {
        printf("%d: %d: 'Y'\n", i, letter);
      } else {
        printf("%d: %d: %c is not a vowel in this case\n", i, letter, letter);
      }
      break;

    default:
      printf("%d: %d: %c is never a vowel\n", i, letter, letter);
    }
  }

  return 0;
}
