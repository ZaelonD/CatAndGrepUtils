#include "function.h"

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "flags.h"

// Метод чтения флагов
int read_flags(int argc, char **argv, flags *flags) {
  int flag, flag_index, err = 0;
  static struct option long_opt[] = {{0, 0, 0, 0}};
  while ((flag = getopt_long(argc, argv, "e:ivclnhsf:o", long_opt,
                             &flag_index)) != -1 &&
         err != 1) {
    if (init_flags(flag, flags) == 1) {
      err = 1;
    }
  }
  return err;
}

// Метод инициализации флагов
int init_flags(int flag, flags *flags) {
  int err = 0;
  switch (flag) {
    case 'e':
      flags->e = 1;
      break;
    case 'i':
      flags->i = 1;
      break;
    case 'v':
      flags->v = 1;
      break;
    case 'c':
      flags->c = 1;
      break;
    case 'l':
      flags->l = 1;
      break;
    case 'n':
      flags->n = 1;
      break;
    case 'h':
      flags->h = 1;
      break;
    case 's':
      flags->s = 1;
      break;
    case 'f':
      flags->f = 1;
      break;
    case 'o':
      flags->o = 1;
      break;
    default:
      err = 1;
      fprintf(stderr, "invalid flag - '%c'", flag);
      break;
  }
  return err;
}