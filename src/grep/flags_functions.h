#ifndef FLAGS_FUNCTIONS
#define FLAGS_FUNCTIONS
#include <stdio.h>

#include "flags.h"

// Метод для использования флага -e
void apply_e_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

// Метод для использования флага -i
void apply_i_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

// Метод для использования флага -v
void apply_v_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

// Метод для использования флага -c
void apply_c_flag(int contains, int *contains_counter, flags *flags);

// Метод для использования флага -l
void apply_l_flag(int contains_in_file, char *file_name, flags *flags);

// Метод для использования флага -n
void apply_n_flag(int contains, int files_count, char *file_name, char *string,
                  int string_count, flags *flags);

// Метод для вывода результата работы флага -с
void print_result_c_flag(int files_count, char *file_name, int contains_counter,
                         flags *flags);

// Метод для вывода результата работы флага -n
void output_for_n_flag(int files_count, char *file_name, char *string,
                       int string_count, flags *flags);

#endif