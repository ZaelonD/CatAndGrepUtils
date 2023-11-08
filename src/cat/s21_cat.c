#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "flags.h"
#include "functions.h"

int main(int argc, char **argv) { return start_cat(argc, argv); }

int start_cat(int argc, char **argv) {
  flags flags = {0};
  int err = 0;
  if (check_argc(argc) == 1) {
    err = 1;
    fprintf(stderr, "No arguments");
  } else if (read_flags(argc, argv, &flags) == 1) {
    err = 1;
  } else
    printf("OK");
  return err;
}

int read_flags(int argc, char **argv, flags *flags) {
  int flag, flag_index, err = 0;
  static struct option long_opt[] = {{"number-nonblank", 0, 0, 'b'},
                                     {"number", 0, 0, 'n'},
                                     {"squeeze-blank", 0, 0, 's'},
                                     {0, 0, 0, 0}};
  while ((flag = getopt_long(argc, argv, "bnestvTE", long_opt, &flag_index)) !=
             -1 &&
         err != 1) {
    if (init_flags(flag, flags) == 1) err = 1;
  }
  return err;
}

int init_flags(int flag, flags *flags) {
  int err = 0;
  switch (flag) {
    case 'b':
      flags->b = 1;
      break;
    case 'e':
      flags->e = 1;
      flags->v = 1;
      break;
    case 'n':
      flags->n = 1;
      break;
    case 's':
      flags->s = 1;
      break;
    case 't':
      flags->t = 1;
      flags->v = 1;
      break;
    case 'v':
      flags->v = 1;
      break;
    case 'E':
      flags->e = 1;
      break;
    case 'T':
      flags->t = 1;
      break;
    default:
      err = 1;
      fprintf(stderr, "usage: cat [-benstuv] [file ...]\n");
      break;
  }
  return err;
}

int check_argc(int argc) {
  int err = 0;
  if (argc < 2) err = 1;
  return err;
}