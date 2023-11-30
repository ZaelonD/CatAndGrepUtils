#ifndef FUNCTION_H
#define FUNCTIONS_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "flags.h"
#define BUFFER_SIZE 256
#define UTIL_NAME "s21_grep"

// Метод для старта программы
int start_grep(int argc, char **argv);

// Метод для чтения флагов
int read_flags(int argc, char **argv, flags *flags);

// Метод для чтения файлов
int read_files(int argc, char **argv, flags *flags);

// Метод для инициализации флагов
int init_flags(int flag, flags *flags);

// Метод вывода результата поиска
void print_search_result(flags *flags, FILE *file, regex_t *preg);

// Метод для проверки количества аргументов
int check_argc(int argc);

#endif