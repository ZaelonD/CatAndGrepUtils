#include "flags_functions.h"

#include <stdio.h>

void apply_s_flag(char current_symbol, char *previous_symbol,
                  int *is_printed_empty_str) {
  if (!(*previous_symbol == '\n' && current_symbol == '\n' &&
        *is_printed_empty_str)) {
    if (*previous_symbol == '\n' && current_symbol == '\n') {
      *is_printed_empty_str = 1;
    } else {
      *is_printed_empty_str = 0;
    }
    fputc(current_symbol, stdout);
  }
  *previous_symbol = current_symbol;
}

void apply_b_flag(char current_symbol, char *previous_symbol,
                  int *line_number) {
  if (current_symbol != '\n' && *previous_symbol == '\n') {
    printf("%6d\t", *line_number += 1);
  }
  *previous_symbol = current_symbol;
}

void apply_n_flag(char current_symbol, char *previous_symbol,
                  int *line_number) {
  if (*previous_symbol == '\n') {
    printf("%6d\t", *line_number += 1);
  }
  *previous_symbol = current_symbol;
}

void apply_v_flag(char *current_symbol) {
  if ((*current_symbol < 32 || *current_symbol == 127) &&
      *current_symbol != 10 && *current_symbol != 9) {
    printf("^");
    if (*current_symbol == 127) {
      *current_symbol = -1;
    }
    *current_symbol += 64;
  }
}

int apply_t_flag(char current_symbol) {
  int result = 0;
  if (current_symbol == 9) {
    printf("^I");
    result = 1;
  }
  return result;
}

void apply_e_flag(char current_symbol) {
  if (current_symbol == '\n') {
    printf("$");
  }
}