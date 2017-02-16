// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#include<stdio.h>

int debug_assert_var=0;

void debug_assert_internal (const int exp) {
  if (!(exp)) {
    fprintf(stderr, "Assertion failed: file \"%s\", line %d\n", __FILE__, __LINE__); 
    fprintf(stderr, "%d", 1/debug_assert_var);
  }
}

void debug_assert_string_internal(const int exp, const char* str) {
  if (!(exp)) {
    fprintf(stderr, "%s\n", str);
    fprintf(stderr, "Assertion failed: file \"%s\", line %d\n", __FILE__, __LINE__); 
    fprintf(stderr, "%d", 1/debug_assert_var);
  }
}
