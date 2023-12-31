#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

#include "flags.h"

// Метод для старта программы
int start_cat(int argc, char **argv);

// Метод для чтения файлов
int read_files(int argc, char **argv, flags *flags);

// Метод чтения флагов
int read_flags(int argc, char **argv, flags *flags);

// Метод инициализации флагов
int init_flags(int flag, flags *flags);

// Проверка на количество аргументов
int check_argc(int argc);

// Метод для вывода файла с флагами
void print_file(flags *flags, FILE *file);

#endif