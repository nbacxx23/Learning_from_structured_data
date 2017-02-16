// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#if DEBUG_ASSERT_ENABLE

void debug_assert_internal (const int exp);
void debug_assert_string_internal(const int exp, const char* str);

#define DEBUG_ASSERT(ex) (debug_assert_internal(ex))
#define DEBUG_ASSERT_STRING(ex, str) (debug_assert_string_internal(ex, str))

#else

#define DEBUG_ASSERT(ex)
#define DEBUG_ASSERT_STRING(ex, str)

#endif
