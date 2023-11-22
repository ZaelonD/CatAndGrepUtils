#ifndef FUNCTION_H
#define FUNCTIONS_H
#include <stdio.h>

#include "flags.h"

// Метод для старта программы
int start_grep(int argc, char **argv);

// Метод для чтения флагов
int read_flags(int argc, char **argv, flags *flags);

// Метод для инициализации флагов
int init_flags(int flag, flags *flags);

// Метод для проверки количества аргументов
int check_argc(int argc);

#endif