#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 0;
  while (i > -25) {
    int j = 0;
    while (j < 25) {
      printf("%d%d ", i, j);
      j++;
    }
    i--;
  }

  return 0;
}
