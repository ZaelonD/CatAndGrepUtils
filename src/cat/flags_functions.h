#ifndef FLAGS_FUNCTIONS
#define FLAGS_FUNCTIONS
#include <stdio.h>

// Метод для использования флага -s
int apply_s_flag(char current_symbol, char *previous_symbol,
                 int *is_printed_empty_str);

// Метод для использования флага -b
void apply_b_flag(char current_symbol, char *previous_symbol, int *line_number);

// Метод для использования флага -n
void apply_n_flag(char previous_symbol, int *line_number);

// Метод для использования флага -t
void apply_t_flag(char *current_symbol);

// Метод для использования флага -e
void apply_e_flag(char current_symbol);

// Метод для использования флага -v
int apply_v_flag(char *current_symbol);

#endif