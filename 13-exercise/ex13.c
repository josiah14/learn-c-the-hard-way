#include <stdio.h>

int main(int argc, char* argv[]) {
  // altered from the orginal - it's bad form to share counter vars between
  // loops.  It's better to initialize the counter in the loop expression, itself,
  // if possible, so I take that approach here, instead, rather than what's in the
  // original text.

  // let's make our own array of strings
  char* states[] = {
    "California",
    "Oregon",
    "Washington",
    "Texas"
  };
  int num_states = 4;

  states[0] = argv[1];
  // go through ecah string in argv
  // Skip argv[0] because it's just the name of the executable
  for (int i = 1; i < argc; i++) {
    // print each string with it's location in the argument list
    printf("arg %d: %s\n", i, argv[i]);
  }

  for (int i = 0; i < num_states; i++) {
    // also altered - it's unnatural to count from 0.  User-friendliness dictates
    // we should start the counting from 1, so we add 1 to i since it starts from
    // 0.
    printf("state %d: %s\n", i + 1, states[i]);
  }

  return 0;
}
