#ifndef RUNTIME_LENGTH_H_
#define RUNTIME_LENGTH_H_

#include <stdlib.h>
#include <stdbool.h>
#include "runtime/point.h"
#include "tree_sitter/runtime.h"

typedef struct {
  uint32_t bytes;
  TSPoint extent;
} Length;

static const Length LENGTH_UNDEFINED = {0, {0, 1}};

static inline bool length_is_undefined(Length length) {
  return length.bytes == 0 && length.extent.column != 0;
}

static inline Length length_min(Length len1, Length len2) {
  return (len1.bytes < len2.bytes) ? len1 : len2;
}

static inline Length length_add(Length len1, Length len2) {
  Length result;
  result.bytes = len1.bytes + len2.bytes;
  result.extent = point_add(len1.extent, len2.extent);
  return result;
}

static inline Length length_sub(Length len1, Length len2) {
  Length result;
  result.bytes = len1.bytes - len2.bytes;
  result.extent = point_sub(len1.extent, len2.extent);
  return result;
}

static inline Length length_zero() {
  Length result = {0, {0, 0}};
  return result;
}

#endif
