#ifndef FUNCTION_H
#define FUNCTIONS_H
#include <stdio.h>

#include "flags.h"

int read_flags(int argc, char **argv, flags *flags);
int init_flags(int flag, flags *flags);

#endif