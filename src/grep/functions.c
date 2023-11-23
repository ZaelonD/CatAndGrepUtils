#include "functions.h"

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "flags.h"

#define UTIL_NAME "s21_grep"

int start_grep(int argc, char **argv) {
  int err = 0;
  flags flags = {0};
  if (!check_argc(argc)) {
    if (read_flags(argc, argv, &flags)) {
      err = 1;
    } else {
      err = read_files(argc, argv, &flags);
    }
  } else {
    err = 1;
  }
  return err;
}

int read_flags(int argc, char **argv, flags *flags) {
  int flag, flag_index, err = 0;
  static struct option long_opt[] = {{0, 0, 0, 0}};
  while ((flag = getopt_long(argc, argv, "e:ivclnhsf:o", long_opt,
                             &flag_index)) != -1 &&
         err != 1) {
    if (init_flags(flag, flags)) {
      err = 1;
    }
  }
  return err;
}

int read_files(int argc, char **argv, flags *flags) {
  int err = 0;
  FILE *file;
  for (int index = optind + 1; index < argc; index++) {
    if ((file = fopen(argv[index], "r")) != NULL) {
      // print_file(flags, file);
      fclose(file);
    } else {
      err = 1;
      fprintf(stderr, "%s%s%s%s", UTIL_NAME, ": ", argv[index],
              ": No such file or directory\n");
    }
  }
  return err;
}

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
      fprintf(stderr, "%s%s%s", "usage: s21_grep",
              " i[-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n",
              "        [-e pattern] [-f file] [--binary-files=value] "
              "[--color=when]\n"
              "        [--context[=num]] [--directories=action] [--label] "
              "[--line-buffered]\n"
              "        [--null] [pattern] [file ...]");
      break;
  }
  return err;
}

int check_argc(int argc) {
  int err = 0;
  if (argc < 2) {
    err = 1;
    fprintf(stderr, "%s%s%s", "usage: s21_grep",
            " i[-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n",
            "        [-e pattern] [-f file] [--binary-files=value] "
            "[--color=when]\n"
            "        [--context[=num]] [--directories=action] [--label] "
            "[--line-buffered]\n"
            "        [--null] [pattern] [file ...]");
  }
  return err;
}