#include <stdio.h>
#include "flags_functions.h"

void apply_s_flag(char current_symbol, char *previous_symbol, int *is_printed_empty_str) {
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