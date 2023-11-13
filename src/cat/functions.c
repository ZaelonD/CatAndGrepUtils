#include "functions.h"

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "flags.h"

int start_cat(int argc, char **argv) {
  flags flags = {0};
  int err = 0;
  if (check_argc(argc)) err = 1;
  else if (!read_flags(argc, argv, &flags)) err = 1;
  else
  printf("%d", get_index(argc, argv));
    // read_files(argc, argv, &flags);
  // printf("OK");
  return err;
}

int read_files(int argc, char **argv, flags *flags) {
  int err = 0;
  FILE *file;
  for (int index = get_index(argc, argv); index < argc; index++) {
    if ((file = fopen(argv[index], "rt")) != NULL) {
      print_file_with_flags(flags, file);
      fclose(file);
    } else {
      fprintf(stderr, "%s%s", argv[index], ": No such file or directory\n");
    }
  }
  // for (int i = 1; i < argc; i++) {
  //   if (argv[i][0] == '-') {
  //     print_file(&argv[i][0]);
  //   }
  // }

  return err;
}

// TODO: Сomplete the method
void print_file_with_flags(flags *flags, FILE *file) {
  
}

int get_index(int argc, char **argv) {
  int exit = 0, index = 1;
  for (; index < argc && exit != 1; index++) {
    if ((argv[index][0]) != '-') exit = 1;
  }
  return index;
}

// void print_file(char *name) {
//   FILE *file = fopen(name, "rt");
//   if (file != NULL) {
//     int c = fgetc(file);
//     while (c != EOF) {
//       putc(c, stdout);
//       c = fgetc(file);
//     }
//     fclose(file);
//   } else {
//     fprintf(stderr, "%s%s", name, ": No such file or directory\n");
//   }
// }

int read_flags(int argc, char **argv, flags *flags) {
  int flag, err = 0;
  static struct option long_opt[] = {{"number-nonblank", 0, 0, 'b'},
                                     {"number", 0, 0, 'n'},
                                     {"squeeze-blank", 0, 0, 's'},
                                     {0, 0, 0, 0}};
  while ((flag = getopt_long(argc, argv, "bnestvTE", long_opt, NULL)) !=
             -1 &&
         err != 1) {
    if (!init_flags(flag, flags)) err = 1;
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