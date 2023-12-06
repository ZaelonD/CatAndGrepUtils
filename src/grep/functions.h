#ifndef FUNCTION_H
#define FUNCTIONS_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flags.h"
#define BUFFER_SIZE 256
#define UTIL_NAME "s21_grep"
// #define ERROR "usage: s21_grep",
// " i[-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] [-C[num]]\n        [-e "
// "pattern] [-f file] [--binary-files=value] [--color=when]\n        "
// "[--context[=num]] [--directories=action] [--label] [--line-buffered]\n "
// "[--null] [pattern] [file ...]"

// Метод для старта программы
int start_grep(int argc, char **argv);

// Метод для чтения флагов
int read_flags(int argc, char **argv, flags *flags);

// Метод для чтения файлов
int read_files(int argc, char **argv, flags *flags);

// Метод для инициализации флагов
int init_flags(int flag, flags *flags);

// Метод вывода результата поиска
void print_search_result(flags *flags, FILE *file, char *file_name,
                         regex_t *regular_expression, int files_count);

// Метод для проверки количества аргументов
int check_argc(int argc);

// Метод для сборки регулярных выражений
void build_pattern(char *pattern, flags *flags);

// Метод для проверки пустой строки в конце файла
void check_enter(char *string, int contains, int string_count,
                 int contains_counter, flags *flags);

void print_error();

#endif