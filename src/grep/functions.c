#include "functions.h"

#include "flags.h"
#include "flags_functions.h"

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
  regex_t regular_expression;
  if (regcomp(&regular_expression, flags->pattern, flags->i))
    err = 1;
  else
    for (int index = optind; index < argc; index++) {
      if ((file = fopen(argv[index], "r")) != NULL) {
        print_search_result(flags, file, argv[index], &regular_expression,
                            files_count);
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
                         regex_t *regular_expression, int files_count) {
  char *string = malloc(sizeof(char) * BUFFER_SIZE);
  regmatch_t match;
  int contains, string_count = 1;
  while (fgets(string, BUFFER_SIZE, file) != NULL) {
    contains = regexec(regular_expression, string, 1, &match, 0);
    if (flags->v) {
      apply_v_flag(contains, files_count, file_name, string, flags);
    }
    if (flags->n) {
      apply_n_flag(contains, files_count, file_name, string, string_count,
                   flags);
    }
    if (flags->e) {
      apply_e_flag(contains, files_count, file_name, string, flags);
    }
    if (flags->i) {
      apply_i_flag(contains, files_count, file_name, string, flags);
    }
    string_count++;
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