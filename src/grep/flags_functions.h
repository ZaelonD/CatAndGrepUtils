#ifndef FLAGS_FUNCTIONS
#define FLAGS_FUNCTIONS
#include <regex.h>
#include <stdio.h>

#include "flags.h"
#include "string.h"

void apply_flags_in_loop(int contains, int files_count, char *file_name,
                         int *string_count, regex_t *regular_expression,
                         char *string, int *contains_counter, flags *flags);

void apply_flags_after_loop(int files_count, char *file_name,
                            int contains_counter, flags *flags);

void print_match(regex_t *regular_expression, char *string, char *file_name,
                 int files_count, int *string_count, flags *flags);

#endif