#include "function.h"

#include <getopt.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int err = 0;
  flags flags = {0};
  if (read_flags(argc, argv, &flags) == 1) {
    err = 1;
  } else
    printf("Ok");
  return err;
}