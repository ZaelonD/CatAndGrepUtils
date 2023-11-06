#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "flags.h"

int main(int argc, char **argv) {
  return start_cat(argc);
}

int start_cat(int argc) {
  int err = 0;
  if (check_argc(argc) == 1) {
    err = 1;
    fprintf(stderr, "No arguments");
  } else {

  }
  return err;
}

int init_flags(int flag, flags *flags) {

}


int check_argc(int argc) {
  int err = 0;
  if (argc < 2)  
    err = 1;
  return err;
}