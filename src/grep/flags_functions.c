#include "flags_functions.h"

void apply_e_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && !flags->n && !flags->v && !flags->c && !flags->l &&
      !flags->h && !flags->s) {
    if (files_count > 1 && !flags->h)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fprintf(stdout, "%s", string);
  }
}

void apply_i_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && !flags->n && !flags->v && !flags->c && !flags->l &&
      !flags->o) {
    if (files_count > 1 && !flags->h)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fprintf(stdout, "%s", string);
  }
}

void apply_v_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (!flags->n && !flags->c && !flags->l && !flags->o) {
    if (contains != 0) {
      if (files_count > 1 && !flags->h)
        fprintf(stdout, "%s:%s", file_name, string);
      else
        fprintf(stdout, "%s", string);
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

void apply_l_flag(int contains, int *contains_counter, char *file_name,
                  flags *flags) {
  (void)file_name;
  if (!flags->c && contains == 0) {
    *contains_counter += 1;
  }
}

void apply_n_flag(int contains, int files_count, char *file_name, char *string,
                  int string_count, flags *flags) {
  if (flags->v && !flags->c && !flags->l && !flags->o && contains != 0)
    output_for_n_flag(files_count, file_name, string, string_count, flags);
  else if (!flags->v && !flags->c && !flags->l && !flags->o && contains == 0)
    output_for_n_flag(files_count, file_name, string, string_count, flags);
}

void apply_h_flag(int contains, flags *flags, char *string) {
  if (contains == 0 && !flags->n && !flags->i && !flags->v && !flags->c &&
      !flags->l && !flags->s && !flags->o)
    fprintf(stdout, "%s", string);
}

void apply_s_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && !flags->n && !flags->v && !flags->c && !flags->l &&
      !flags->i && !flags->o) {
    if (files_count > 1 && !flags->h)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fprintf(stdout, "%s", string);
  }
}

void apply_f_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags) {
  if (contains == 0 && !flags->n && !flags->v && !flags->c && !flags->l &&
      !flags->i && !flags->s) {
    if (files_count > 1 && !flags->h)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fprintf(stdout, "%s", string);
  }
}

void apply_o_flag(regex_t *regular_expression, regmatch_t *match,
                  int files_count, char *file_name, int *contains_counter,
                  char *string, int string_count, flags *flags) {
  if (!flags->v && !flags->c && !flags->l) {
    int offset = 0, result;
    while ((result = regexec(regular_expression, string + offset, 1, match,
                             0)) == 0) {
      *contains_counter += 1;
      if (files_count > 1 && !flags->n && !flags->h) {
        fprintf(stdout, "%s:", file_name);
      }
      if (flags->n) {
        fprintf(stdout, "%s:%d:", file_name, string_count);
      }
      for (int i = match->rm_so; i < match->rm_eo; i++) {
        putchar((string + offset)[i]);
      }
      putchar('\n');
      offset += match->rm_eo;
    }
  }
}

void print_result_c_flag(int files_count, char *file_name, int contains_counter,
                         flags *flags) {
  if (files_count > 1 && !flags->l && !flags->h) {
    fprintf(stdout, "%s:%d", file_name, contains_counter);
  } else if ((files_count == 1 && !flags->l) ||
             (files_count > 1 && flags->h && !flags->l)) {
    fprintf(stdout, "%d", contains_counter);
  } else if (files_count > 1 && flags->l && contains_counter != 0) {
    fprintf(stdout, "%s:1", file_name);
  } else if (files_count > 1 && flags->l && contains_counter == 0) {
    fprintf(stdout, "%s:0", file_name);
  } else {
    fprintf(stdout, "%d", 1);
  }
  if (flags->l && contains_counter != 0) {
    putchar('\n');
  }
}

void print_result_l_flag(int files_count, char *file_name, int contains_counter,
                         int string_count, flags *flags) {
  (void)files_count;
  if ((contains_counter >= 1 && flags->l) ||
      (flags->v && flags->l && string_count != 1)) {
    fprintf(stdout, "%s", file_name);
  }
}

void output_for_n_flag(int files_count, char *file_name, char *string,
                       int string_count, flags *flags) {
  if (files_count > 1 && !flags->h)
    fprintf(stdout, "%s:%d:%s", file_name, string_count, string);
  else
    fprintf(stdout, "%d:%s", string_count, string);
}

void print_result_without_flags(int contains, int files_count, char *file_name,
                                char *string) {
  if (contains == 0) {
    if (files_count > 1)
      fprintf(stdout, "%s:%s", file_name, string);
    else
      fprintf(stdout, "%s", string);
  }
}