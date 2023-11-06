#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "flags.h"

int main(int argc, char **argv) {
  int err = 0;
  if (check_argc(argc) == 1)
  {
    printf("Error");
  } else {
    printf("OK");
  }
  return err;
}

int check_argc(int argc) {
  int err = 0;
  if (argc < 2)  
    err = 1;
  return err;
}