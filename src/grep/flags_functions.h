#ifndef FLAGS_FUNCTIONS
#define FLAGS_FUNCTIONS
#include <stdio.h>

#include "flags.h"

void apply_n_flag(int contains, int files_count, char *file_name, char *string,
                  int string_count, flags *flags);

void apply_v_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

void apply_e_flag(int contains, int files_count, char *file_name, char *string,
                  flags *flags);

#endif