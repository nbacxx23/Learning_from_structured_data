// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

/*
**  INCLUDES
*/ 

#include<stdio.h>
/* #include<stdlib.h> */
#include<math.h>
#include<string.h>
#include<time.h>

#define DEBUG_ASSERT_ENABLE 1
#include"debug_assert.H"

#define APPLY_RULES 1

/*
#define SITE_LISTS 0
const int recycle_site_list_memory=1;

#define POS_CLASSES 0
const int using_pos_tag_classes=0;

#define USE_RATIO_SCORE 0

const int write_trace_file = 1;

const int do_rule_deactivation = 0;
const int deactivate_denom = 2;
const int reactivate_add_frac_denom = 5;

const double neg_discount_factor = 1.0;
const right_to_left = 0;
#define TWO_PASS_APPLY 0
*/

/*
**  CONSTANTS
*/ 

const int max_tags = 9;
const int max_tag_width = 3;
const int max_pos_tags = 100;
const int max_pos_tag_width = 6;
const int max_word_width = 80;
const int max_sentences = 15000;
const int max_sentence_length = 800;
const int max_dict_words = 30000;
//const int max_dict_words = 15000;
const int max_dict_chars = 300000;
//const int max_words = 150000;
//const int max_words = 200000;
const int max_words = 300000;
const int max_tags_per_word = 5;

const int max_templates = 120;
const int max_template_chars = 1200;
const int max_rule_args = 7;
const int max_site_list_length = max_words;
// maximum alternatives in a disjunctive template
const int max_alt_count = 3;

const int bufsize = 200;
const int max_patterns = 1;  // max ORed patterns in a rule
//const int pattern_width = 3;  // width each side of old tag
const int pattern_width = 2;  // width each side of old tag
#if APPLY_RULES
const int hash_table_size = 7; // not using it in this case
#else
//const int hash_table_size = 107;  // must be prime
//const int hash_table_size = 1031;  // must be prime
//const int hash_table_size = 15013;  // must be prime
//const int hash_table_size = 75011;  // must be prime
//const int hash_table_size = 250007;  // must be prime
//const int hash_table_size = 500009;  // must be prime
//const int hash_table_size = 800011;  // must be prime
//const int hash_table_size = 1200007;  // must be prime
//const int hash_table_size = 1500007;  // must be prime
const int hash_table_size = 2000003;  // must be prime
#endif
const int max_rule_def_string_length = 
  (2 * max_tag_width) + (max_patterns * 2 * pattern_width * max_tag_width) +1;
const unsigned char sentence_break_tag_num = 1;
const char *const sentence_break_tag = "ZZ";

const char *const end_sentence_tag = "Z";
const char *const end_sentence_pos_tag = "ZZZ";
const char *const end_sentence_word = "ZZZ";

const int max_rule_ptrs = 250;

const char tag_output_pad_char='_';

const double ninf = -1e100;

const int max_int = 2147483647;
const double range_of_long = 4294967296.0;
