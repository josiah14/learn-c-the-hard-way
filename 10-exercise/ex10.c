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

    switch (letter) {
    case 'a': // fall through
    case 'A':
      printf("%d: 'A'\n", i);
      break;
    case 'e': // fall through
    case 'E':
      printf("%d: 'E'\n", i);
      break;
    case 'i': // fall through
    case 'I':
      printf("%d: 'I'\n", i);
      break;
    case 'o': // fall through
    case 'O':
      printf("%d: 'O'\n", i);
      break;
    case 'u': // fall through
    case 'U':
      printf("%d: 'U'\n", i);
      break;
    case 'y': // fall through
    case 'Y':
      // Y is only a vowel sometimes
      if (i > 2) {
        printf("%d: 'Y'\n", i);
      } else {
        printf("%d: %c is not a vowel in this case\n", i, letter);
      }
      break;

    default:
      printf("%d: %c is never a vowel\n", i, letter);
    }
  }

  return 0;
}
