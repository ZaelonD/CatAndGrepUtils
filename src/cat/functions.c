#include "functions.h"

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "flags.h"

int start_cat(int argc, char **argv) {
  flags flags = {0};
  int err = 0;
  if (check_argc(argc) == 1) {
    err = 1;
    fprintf(stderr, "No arguments");
  } else if (read_flags(argc, argv, &flags) == 1) {
    err = 1;
  } else
    read_files(argc, argv, &flags);
  // printf("OK");
  return err;
}

int read_files(int argc, char **argv, flags *flags) {
  int err = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      print_file(&argv[i][0]);
    }
  }

  return err;
}

void print_file_with_flags(flags *flags, char *name) {
  FILE *file = fopen(name, "rt");
  if (file != NULL) {
    int c = fgetc(file), str_count = 1;
    while (c != EOF) {
      if (flags->b) {
        printf("%d%d", str_count, putc(c, stdout));
        c = fgetc(file);
        str_count++;
      }
    }
  }
}

void print_file(char *name) {
  FILE *file = fopen(name, "rt");
  if (file != NULL) {
    int c = fgetc(file);
    while (c != EOF) {
      putc(c, stdout);
      c = fgetc(file);
    }
    fclose(file);
  } else {
    fprintf(stderr, "%s%s", name, ": No such file or directory\n");
  }
}

int read_flags(int argc, char **argv, flags *flags) {
  int flag, err = 0;
  static struct option long_opt[] = {{"number-nonblank", 0, 0, 'b'},
                                     {"number", 0, 0, 'n'},
                                     {"squeeze-blank", 0, 0, 's'},
                                     {0, 0, 0, 0}};
  while ((flag = getopt_long(argc, argv, "bnestvTE", long_opt, NULL)) !=
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