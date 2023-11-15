#ifndef FLAGS_FUNCTIONS
#define FLAGS_FUNCTIONS
#include <stdio.h>

// Метод для использования флага -s
void apply_s_flag(char current_symbol, char *previous_symbol, int *is_printed_empty_str);

// Метод для использования флага -b
void apply_b_flag(char current_symbol, char *previous_symbol, int *line_number);

#endif