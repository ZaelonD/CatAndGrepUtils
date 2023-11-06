#ifndef S21CAT_H
#define S21CAT_H
#include <stdio.h>

typedef struct {
  int b;  // Нумерует только непустые строки
  int e;  // Также отображает символы конца строки как $
  int n;  // Нумерует все выходные строки
  int s;  // Сжимает несколько смежных пустых строк
  int t;  // также отображает табы как ^I
  int v;
} flags;

#endif