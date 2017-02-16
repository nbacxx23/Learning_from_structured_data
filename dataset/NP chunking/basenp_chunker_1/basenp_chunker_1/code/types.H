// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

/*
**   TYPES
*/

typedef unsigned char tag_num_type;
typedef char tag_string_type[max_tag_width];

typedef unsigned char pos_tag_num_type;
typedef char pos_tag_string_type[max_pos_tag_width];

typedef int word_num_type;
typedef char word_string_type[max_word_width];

/* Must be as large as the largest of tag_num_type, pos_tag_num_type,
   and word_num_type */
typedef int templ_arg_type;

typedef tag_num_type poss_tag_type[max_tags_per_word];
typedef unsigned char tag_count_type;

// used for number of words in sentence to left and right
typedef short words_left_num_type;

// where templ_enum used to be, which is now in its own file

enum arg_type_enum {
  TAG,
  POS_TAG,
  WORD
  };

enum rule_status_enum {
  EMPTY,
  ACTIVE,
  INACTIVE,
  OLD,
  FULL
  };

class locus_class {
public:
  int sent, word;
  locus_class(int s=0, int w=0) { sent = s; word = w; }
  int operator==(const locus_class other_locus) {
    return (sent == other_locus.sent && word == other_locus.word); }
  int operator!=(const locus_class other_locus) {
    return (sent != other_locus.sent || word != other_locus.word); }
  void print() { printf("S: %6d W: %4d\n", sent, word); }
  int trainp();
};

#if SITE_LISTS
class site_list_class {
public:
  int *sites;
  int length;
  site_list_class() {
    sites = 0;
    length = 0;
  }
  site_list_class(const int len) {
    sites = new int[len];
    length = len;
  }
  site_list_class(const int* buf, const int len) {
    sites = new int[len];
    length = len;
    for (int i=0; i<len; i++) {
      sites[i] = buf[i];
    }
  }
  void clear_fields() {
    if (sites)
      delete sites;
  }
};
#endif

class string_table {
public:
  int next_ind;
  char *str;
  int *ind;
  int next_str;
  int ind_max;
  int char_max;
  int add_string_at_end(const char* st);
  string_table(int max_count, int max_chars);
  virtual int add_string(const char* st) = 0;
  virtual int look_up(const char* st) = 0;
  char *string(int index) { return(&str[ind[index]]); }
  int count() { return (next_ind - 1); }
};

class unsorted_string_table : public string_table {
public:
  unsorted_string_table(int max_count, int max_chars) 
  : string_table(max_count, max_chars) {}
  int add_string(const char* st);
  int look_up(const char* st);
};

class sorted_string_table : public string_table {
public:
  sorted_string_table(int max_count, int max_chars)
  : string_table(max_count, max_chars) {}
  int add_string(const char* st);
  int look_up(const char* st);
};

class rule_type {
 public:
  // must not have internal holes
  // word-aligned elements must precede byte-aligned ones
  int arg_count;
  templ_arg_type args[max_rule_args];
  tag_num_type new_tag;
  templ_type templ;
  rule_type() {
    arg_count = 0;
    for (int i=0; i<max_rule_args; i++)
      args[i] = 0;
    new_tag = 0;
    templ = NO_TEMPL;
  }
};

// Word Recs

struct word_rec {
 word_num_type word;
 words_left_num_type left;
 words_left_num_type right;
 pos_tag_num_type pos_tag;
 tag_num_type corr_tag;
 tag_num_type cur_tag;
 tag_num_type new_tag;
 poss_tag_type poss_tags;
 tag_count_type poss_tags_count;
};

typedef word_rec *word_rec_ptr_type;
typedef word_rec_ptr_type text_type[max_words];

struct sentence_index_entry_type {
  int start;
  int count;
};
