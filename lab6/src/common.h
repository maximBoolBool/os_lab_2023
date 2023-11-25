#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

struct FactorialArgs{
  uint64_t begin;
  uint64_t end;
  uint64_t mod;
};

//Прототип функции для умножения по модулю
uint64_t MultModulo(uint64_t a, uint64_t b, uint64_t mod);

#endif
