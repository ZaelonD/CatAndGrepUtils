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
  free(flags.pattern);
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
  if (flags->pattern_length == 0 && err != 1)
    build_pattern(argv[optind++], flags);
  return err;
}

int read_files(int argc, char **argv, flags *flags) {
  int err = 0, files_count = argc - optind;
  FILE *file;
  regex_t regular_expression;
  if (regcomp(&regular_expression, flags->pattern, REG_EXTENDED | flags->i))
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
          fprintf(stderr, "%s: %s%s", UTIL_NAME, argv[index],
                  ": No such file or directory\n");
      }
    }
  regfree(&regular_expression);
  return err;
}

void print_search_result(flags *flags, FILE *file, char *file_name,
                         regex_t *regular_expression, int files_count) {
  char *string = malloc(sizeof(char) * BUFFER_SIZE);
  regmatch_t match;
  int contains, contains_counter = 0, string_count = 1;
  while (fgets(string, BUFFER_SIZE, file) != NULL) {
    contains = regexec(regular_expression, string, 1, &match, 0);
    apply_flags_in_loop(contains, files_count, file_name, &string_count,
                        regular_expression, string, &contains_counter, flags);
  }
  apply_flags_after_loop(files_count, file_name, contains_counter, flags);
  free(string);
}

void build_pattern(char *pattern, flags *flags) {
  if (flags->pattern_length == 0) {
    flags->pattern = malloc(1024 * sizeof(char));
  }
  if (1024 < flags->pattern_length + strlen(pattern)) {
    flags->pattern = realloc(flags->pattern, 1024 * 2);
  }
  if (flags->pattern_length != 0) {
    strcat(flags->pattern + flags->pattern_length++, "|");
  }
  flags->pattern_length +=
      sprintf(flags->pattern + flags->pattern_length, "(%s)", pattern);
}

void check_enter(char *string, int contains, int contains_counter,
                 flags *flags) {
  if ((strstr(string, "\n") == NULL && contains_counter > 0 && !flags->o) ||
      flags->c || (flags->l && contains_counter > 0) ||
      (flags->l && flags->v && contains != 0) ||
      (flags->v && strstr(string, "\n") == NULL && contains != 0)) {
    putchar('\n');
  }
}

int get_pattern_from_file(char *file_name, flags *flags) {
  int err = 0;
  FILE *file;
  if ((file = fopen(file_name, "r")) != NULL) {
    char *string = malloc(sizeof(char) * BUFFER_SIZE);
    while (fgets(string, BUFFER_SIZE, file) != NULL) {
      if (strstr(string, "\n") != NULL) {
        string[strlen(string) - 1] = '\0';
      }
      build_pattern(string, flags);
    }
    free(string);
    fclose(file);
  } else {
    err = 1;
    if (!flags->s)
      fprintf(stderr, "%s: %s%s", UTIL_NAME, file_name,
              ": No such file or directory\n");
  }
  return err;
}

int init_flags(int flag, flags *flags) {
  int err = 0;
  switch (flag) {
    case 'e':
      flags->e = 1;
      build_pattern(optarg, flags);
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
      err = get_pattern_from_file(optarg, flags);
      break;
    case 'o':
      flags->o = 1;
      break;
    default:
      err = 1;
      print_error();
      break;
  }
  return err;
}

int check_argc(int argc) {
  int err = 0;
  if (argc < 2) {
    err = 1;
    print_error();
  }
  return err;
}

void print_error() {
  fprintf(stderr, "%s%s%s\n", "usage: s21_grep",
          " i[-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n",
          "        [-e pattern] [-f file] [--binary-files=value] "
          "[--color=when]\n"
          "        [--context[=num]] [--directories=action] [--label] "
          "[--line-buffered]\n"
          "        [--null] [pattern] [file ...]");
}