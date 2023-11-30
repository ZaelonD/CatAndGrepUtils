#ifndef FLAGS_FUNCTIONS
#define FLAGS_FUNCTIONS
#include <stdio.h>

#include "flags.h"

// Метод для использования флага -n
void apply_n_flag(int contains, int files_count, char *file_name, char *string,
                  int string_count, flags *flags);

// Метод для использования флага -v
void apply_v_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

// Метод для использования флага -e
void apply_e_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

// Метод для использования флага -i
void apply_i_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

#endif