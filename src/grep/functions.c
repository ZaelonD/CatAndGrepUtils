#include "functions.h"

#include "flags.h"

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
  int flag, err = 0;
  while ((flag = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1 &&
         err != 1) {
    if (init_flags(flag, flags)) {
      err = 1;
    }
  }
  if (flags->pattern == NULL) flags->pattern = argv[optind++];
  return err;
}

int read_files(int argc, char **argv, flags *flags) {
  int err = 0, files_count = argc - optind;
  FILE *file;
  regex_t preg;
  if (regcomp(&preg, flags->pattern, flags->i))
    err = 1;
  else
    for (int index = optind; index < argc; index++) {
      if ((file = fopen(argv[index], "r")) != NULL) {
        print_search_result(flags, file, argv[index], &preg, files_count);
        fclose(file);
      } else {
        err = 1;
        if (!flags->s)
          fprintf(stderr, "%s%s%s%s", UTIL_NAME, ": ", argv[index],
                  ": No such file or directory\n");
      }
    }
  return err;
}

void print_search_result(flags *flags, FILE *file, char *file_name,
                         regex_t *preg, int files_count) {
  char *string = malloc(sizeof(char) * BUFFER_SIZE);
  regmatch_t match;
  (void)flags;
  while (fgets(string, BUFFER_SIZE, file) != NULL) {
    if (!regexec(preg, string, 1, &match, 0)) {
      if (files_count > 1)
        fprintf(stdout, "%s:%s", file_name, string);
      else
        fputs(string, stdout);
    }
  }
  free(string);
}

int init_flags(int flag, flags *flags) {
  int err = 0;
  switch (flag) {
    case 'e':
      flags->e = 1;
      flags->pattern = optarg;
      break;
    case 'i':
      flags->i = REG_ICASE;
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