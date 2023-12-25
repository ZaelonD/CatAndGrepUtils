#include "flags_functions.h"

void apply_flags_in_loop(int contains, int files_count, char *file_name,
                         int *string_count, regex_t *regular_expression,
                         char *string, int *contains_counter, flags *flags) {
  if ((contains == 0 && !flags->v) || (contains != 0 && flags->v)) {
    if (!flags->c && !flags->l) {
      if (!flags->h && files_count > 1 && !flags->o) {
        fprintf(stdout, "%s:", file_name);
      }
      if (flags->n && !flags->o) {
        fprintf(stdout, "%d:", *string_count);
      }
      if (flags->o && !flags->v) {
        print_match(regular_expression, string, file_name, files_count,
                    string_count, flags);
      } else if (!flags->v || (flags->v && !flags->o))
        fprintf(stdout, "%s", string);
      if (strstr(string, "\n") == NULL && !flags->o) {
        putchar('\n');
      }
    }
    *contains_counter += 1;
  }
  *string_count += 1;
}

void apply_flags_after_loop(int files_count, char *file_name,
                            int contains_counter, flags *flags) {
  if (flags->c && !flags->l) {
    if (!flags->h && files_count > 1) {
      fprintf(stdout, "%s:", file_name);
    }
    fprintf(stdout, "%d\n", contains_counter);
  }
  if (flags->l && contains_counter > 0) {
    fprintf(stdout, "%s\n", file_name);
  }
}

void print_match(regex_t *regular_expression, char *string, char *file_name,
                 int files_count, int *string_count, flags *flags) {
  regmatch_t match;
  int offset = 0;
  while (1) {
    int result = regexec(regular_expression, string + offset, 1, &match, 0);
    if (result != 0) {
      break;
    }
    if (!flags->h && files_count > 1) {
      fprintf(stdout, "%s:", file_name);
    }
    if (flags->n) {
      fprintf(stdout, "%d:", *string_count);
    }
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      putchar((string)[i + offset]);
    }
    putchar('\n');
    offset += match.rm_eo;
  }
}