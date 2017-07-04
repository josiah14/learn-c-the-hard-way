#include <stdio.h>

int main(int argc, char* argv[]) {
  int i = 0;

  // go through ecah string in argv
  // Skip argv[0] because it's just the name of the executable
  for (int i = 1; i < argc; i++) {
    // print each string with it's location in the argument list
    printf("arg %d: %s\n", i, argv[i]);
  }

  // let's make our own array of strings
  char* states[] = {
    "California",
    "Oregon",
    "Washington",
    "Texas"
  };
  int num_states = 4;

  for (int i = 0; i < num_states; i++) {
    printf("state %d; %s\n", i, states[i]);
  }

  return 0;
}
