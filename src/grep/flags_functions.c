#include "flags_functions.h"

void apply_n_flag(int contains, int files_count, char *file_name, char *string,
                  int string_count, flags *flags) {
  if (flags->v && contains != 0) {
    if (files_count > 1)
      fprintf(stdout, "%s:%d:%s", file_name, string_count, string);
    else
      fprintf(stdout, "%d:%s", string_count, string);
  } else if (!flags->v && contains == 0) {
    if (files_count > 1)
      fprintf(stdout, "%s:%d:%s", file_name, string_count, string);
    else
      fprintf(stdout, "%d:%s", string_count, string);
  }
}

void apply_v_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (!flags->n) {
    if (contains != 0) {
      if (files_count > 1)
        fprintf(stdout, "%s:%s", file_name, string);
      else
        fputs(string, stdout);
    }
  }
}

void apply_e_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && (!flags->n && !flags->v)) {
    if (files_count > 1)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fputs(string, stdout);
  }
}