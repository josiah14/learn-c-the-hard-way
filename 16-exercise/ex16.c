#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char* name;
  int age;
  int height;
  int weight;
};

struct Person* Person_create(char* name, int age, int height, int weight) {
  struct Person* who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person* who) {
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person* who) {
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char* argv[]) {
  // make two people structures
  struct Person* josiah = Person_create("Josiah Berkebile", 32, 74, 170);
  struct Person* joanna = Person_create("Joanna Carey Berkebile", 28, 69, 145);

  // print them and their memory locations out
  printf("Josiah is at memory location %p:\n", josiah);
  Person_print(josiah);

  printf("Joanna is at memory location %p:\n", joanna);
  Person_print(joanna);

  // this is how you would append to a string in a struct
  char* name = malloc(strlen(josiah->name) + strlen(": This was appended.") + 1);
  strcpy(name, josiah->name);
  strcat(name, ": This was appended.");
  josiah->name = realloc(josiah->name, strlen(name) + 1);
  strcpy(josiah->name, name);
  free(name);

  // make everyone age 2 years older and print them, again
  josiah->age += 2;
  joanna->age += 2;
  // actually, let's just alter a lot of things and see how things turn out.
  josiah->height -= 2;
  josiah->weight *= 3;
  Person_print(josiah);
  Person_print(joanna);

  // Clean-up after yourself, dude
  Person_destroy(josiah);
  Person_destroy(joanna);

  return 0;
}
