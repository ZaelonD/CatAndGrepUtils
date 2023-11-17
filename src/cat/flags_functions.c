#include "flags_functions.h"

#include <stdio.h>

int apply_s_flag(char current_symbol, char *previous_symbol,
                  int *is_printed_empty_str) {
  int result = 0;
  if (current_symbol =='\n' && *previous_symbol == '\n') {
    *is_printed_empty_str += 1;
  } else {
    *is_printed_empty_str = 0;
  }
  if (*is_printed_empty_str > 1) {
    result = 1;
  }
  return result;
}

void apply_b_flag(char current_symbol, char *previous_symbol,
                  int *line_number) {
  if (current_symbol != '\n' && *previous_symbol == '\n') {
    printf("%6d\t", *line_number += 1);
  }
}

void apply_n_flag(char previous_symbol, int *line_number) {
  if (previous_symbol == '\n') {
    printf("%6d\t", *line_number += 1);
  }
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

void apply_t_flag(char *current_symbol) {
  if (*current_symbol == '\t') {
    printf("^");
    *current_symbol = 'I';
  }
}

void apply_e_flag(char current_symbol) {
  if (current_symbol == '\n') {
    printf("$");
  }
}