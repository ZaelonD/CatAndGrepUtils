#include "flags_functions.h"

void apply_n_flag(int contains, int files_count, char *file_name, char *string,
                  int string_count, flags *flags) {
  if (flags->v && contains != 0 && !flags->c) {
    if (files_count > 1)
      fprintf(stdout, "%s:%d:%s", file_name, string_count, string);
    else
      fprintf(stdout, "%d:%s", string_count, string);
  } else if ((!flags->v && !flags->c) && contains == 0) {
    if (files_count > 1)
      fprintf(stdout, "%s:%d:%s", file_name, string_count, string);
    else
      fprintf(stdout, "%d:%s", string_count, string);
  }
}

void apply_v_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (!flags->n && !flags->c) {
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
  if (contains == 0 && (!flags->n && !flags->v && !flags->c)) {
    if (files_count > 1)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fputs(string, stdout);
  }
}

void apply_i_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && (!flags->n && !flags->v && !flags->c)) {
    if (files_count > 1)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fputs(string, stdout);
  }
}

void apply_c_flag(int contains, int *contains_counter, flags *flags) {
  if (contains != 0 && flags->v) {
    *contains_counter += 1;
  } else if (contains == 0 && !flags->v) {
    *contains_counter += 1;
  }
}

void print_result_c_flag(int files_count, char *file_name,
                         int contains_counter) {
  if (files_count > 1) {
    fprintf(stdout, "%s:%d\n", file_name, contains_counter);
  } else {
    fprintf(stdout, "%d", contains_counter);
  }
}