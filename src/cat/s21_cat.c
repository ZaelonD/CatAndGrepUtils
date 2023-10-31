#include <stdio.h>
#include <string.h>

void print_file(char *name);

int main(int argc, char **argv) {
  int err = 0;
  if (*argv[1] != '-' || strcmp(argv[1], "--") == 0) {
    err = 1;
  } else
    printf("Correct");
  if (err == 1) {
    printf("Incorrect");
    return 1;
  } else
    for (int i = 1; i < argc; i++) {
      print_file(argv[i]);
    }
  return 0;
}

// void parse_flags(int argc, char **argv) {}

void print_file(char *name) {
  FILE *f = fopen(name, "rt");

  if (f != NULL) {
    int c = fgetc(f);
    while (c != EOF) {
      putc(c, stdout);
      c = fgetc(f);
    }
    fclose(f);
  }
}