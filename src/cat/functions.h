#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include "flags.h"

// Метод для старта программы
int start_cat(int argc, char **argv);

// Метод чтения флагов
int read_flags(int argc, char **argv, flags *flags);

// Метод инициализации флагов
int init_flags(int flag, flags *flags);

// Проверка на количество аргументов
int check_argc(int argc);

#endif