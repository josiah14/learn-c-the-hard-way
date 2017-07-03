#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("ERROR: You need at least one argument.\n");
    // early program abortion due to error
    // use a non-zero return code to indicate error.
    return 1;
  }

  for (int i = 1; argv[i] != '\0'; i++) {
    printf("argument %d: \n", i);
    for (int j = 0; argv[i][j] != '\0'; j++) {
      char letter = ',';
      letter = argv[i][j];
      // to uppercase
      if (letter > 90) {
        letter = letter - 32;
      }

      switch (letter) {
      case 'a': // fall through
      case 'A':
        printf("%d: %d: 'A'\n", j, letter);
        break;
      case 'E':
        printf("%d: %d: 'E'\n", j, letter);
        break;
      case 'I':
        printf("%d: %d: 'I'\n", j, letter);
        break;
      case 'O':
        printf("%d: %d: 'O'\n", j, letter);
        break;
      case 'U':
        printf("%d: %d: 'U'\n", j, letter);
        break;
      case 'Y':
        // Y is only a vowel sometimes
        if (j > 2) {
          printf("%d: %d: 'Y'\n", j, letter);
        } else {
          printf("%d: %d: %c is not a vowel in this case\n", j, letter, letter);
        }
        break;

      default:
        printf("%d: %d: %c is never a vowel\n", j, letter, letter);
      }
    }
  }

  return 0;
}
