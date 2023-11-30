#include "flags_functions.h"

void apply_e_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && !flags->n && !flags->v && !flags->c) {
    if (files_count > 1)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fprintf(stdout, string);
  }
}

void apply_i_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && !flags->n && !flags->v && !flags->c && !flags->l) {
    if (files_count > 1)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fprintf(stdout, string);
  }
}

void apply_v_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (!flags->n && !flags->c && !flags->l) {
    if (contains != 0) {
      if (files_count > 1)
        fprintf(stdout, "%s:%s", file_name, string);
      else
        fprintf(stdout, string);
    }
  }
}

void apply_c_flag(int contains, int *contains_counter, flags *flags) {
  if (contains != 0 && flags->v) {
    *contains_counter += 1;
  } else if (contains == 0 && !flags->v) {
    *contains_counter += 1;
  }
}

void apply_l_flag(int contains_in_file, char *file_name, flags *flags) {
  (void)flags;
  if (contains_in_file >= 1) {
    fprintf(stdout, "%s\n", file_name);
  }
}

void apply_n_flag(int contains, int files_count, char *file_name, char *string,
                  int string_count, flags *flags) {
  if (flags->v && !flags->c && contains != 0 && !flags->l) {
    if (files_count > 1)
      fprintf(stdout, "%s:%d:%s", file_name, string_count, string);
    else
      fprintf(stdout, "%d:%s", string_count, string);
  } else if (!flags->v && !flags->c && !flags->l && contains == 0) {
    if (files_count > 1)
      fprintf(stdout, "%s:%d:%s", file_name, string_count, string);
    else
      fprintf(stdout, "%d:%s", string_count, string);
  }
}

void print_result_c_flag(int files_count, char *file_name, int contains_counter,
                         flags *flags) {
  if (files_count > 1 && !flags->l) {
    fprintf(stdout, "%s:%d\n", file_name, contains_counter);
  } else if (files_count == 1 && !flags->l) {
    fprintf(stdout, "%d", contains_counter);
  } else if (files_count > 1 && flags->l) {
    fprintf(stdout, "%s:1\n", file_name);
  } else {
    fprintf(stdout, "%d\n", 1);
  }
}