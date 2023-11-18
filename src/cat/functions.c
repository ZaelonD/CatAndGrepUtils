#include "functions.h"

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "flags.h"
#include "flags_functions.h"

int start_cat(int argc, char **argv) {
  flags flags = {0};
  int err = 0;
  if (!check_argc(argc)) {
    if (read_flags(argc, argv, &flags)) {
      err = 1;
    } else {
      read_files(argc, argv, &flags);
    }
  } else {
    err = 1;
  }
  return err;
}

int read_files(int argc, char **argv, flags *flags) {
  int err = 0;
  FILE *file;
  for (int index = optind; index < argc; index++) {
    if ((file = fopen(argv[index], "r")) != NULL) {
      print_file(flags, file);
      fclose(file);
    } else {
      err = 1;
      fprintf(stderr, "%s%s%s", "s21_cat: ", argv[index],
              ": No such file or directory\n");
    }
  }
  return err;
}

void print_file(flags *flags, FILE *file) {
  char current_symbol = 0, previous_symbol = '\n';
  int is_printed_empty_str = 0, line_number = 0;
  while ((current_symbol = fgetc(file)) != EOF) {
    if (flags->s) {
      if (apply_s_flag(current_symbol, &previous_symbol, &is_printed_empty_str))
        continue;
    }
    if (flags->b) {
      apply_b_flag(current_symbol, &previous_symbol, &line_number);
    }
    if (flags->n) {
      apply_n_flag(previous_symbol, &line_number);
    }
    if (flags->t) {
      apply_t_flag(&current_symbol);
    }
    if (flags->e) {
      apply_e_flag(current_symbol);
    }
    if (flags->v) {
      if (apply_v_flag(&current_symbol)) continue;
    }
    fputc(current_symbol, stdout);
    previous_symbol = current_symbol;
  }
}

int read_flags(int argc, char **argv, flags *flags) {
  int flag, err = 0;
  static struct option long_opt[] = {{"number-nonblank", 0, 0, 'b'},
                                     {"number", 0, 0, 'n'},
                                     {"squeeze-blank", 0, 0, 's'},
                                     {0, 0, 0, 0}};
  while ((flag = getopt_long(argc, argv, "benstvTE", long_opt, NULL)) != -1 &&
         err != 1) {
    if (init_flags(flag, flags)) err = 1;
  }
  return err;
}

int init_flags(int flag, flags *flags) {
  int err = 0;
  switch (flag) {
    case 'b':
      flags->b = 1;
      flags->n = 0;
      break;
    case 'e':
      flags->e = 1;
      flags->v = 1;
      break;
    case 'n':
      flags->n = flags->b == 1 ? 0 : 1;
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
  if (argc < 2) {
    err = 1;
    fprintf(stderr, "No arguments");
  }
  return err;
}