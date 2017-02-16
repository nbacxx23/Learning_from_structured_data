// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#include "defns.H"
#include "templ_enum.H"
#include "types.H"
#include "extern.H"
#include "rules.H"
#include "templates.H"

FILE *rules_fptr;
FILE *new_corpus_fptr;

void open_rules_file() {
  if ((rules_fptr = fopen(apply_rules_file, "r")) == NULL)
    fprintf(stderr, "File of rules to apply could not be opened.\n");
}

void close_rules_file() {
  fclose(rules_fptr);
}

int read_rule_line(rule_type *rule_ptr) {
  char ch;
  rule_type result;
  fscanf(rules_fptr, "%s%c", line_buffer, &ch);
  if (feof(rules_fptr))
    return(0);
  /* look up the template */
  result.templ = (templ_type) templ_table.look_up(line_buffer);
  result.arg_count = templ_arg_count(result.templ);
  int i;
  for (i=0; i<result.arg_count; i++) {
    fscanf(rules_fptr, "%s%c", line_buffer, &ch);
    DEBUG_ASSERT(ch != '\n');
    switch (find_templ_arg_type(result.templ, i)) {
    case TAG:
      result.args[i]=tag_table.look_up(line_buffer);
      break;
    case POS_TAG:
      result.args[i]=pos_tag_table.look_up(line_buffer);
      break;
    case WORD:
      result.args[i]=word_table.look_up(line_buffer);
      break;
    }
  }
  for ( ; i<max_rule_args; i++)
    result.args[i] = 0;
  fscanf(rules_fptr, "%s%c", line_buffer, &ch);
  DEBUG_ASSERT(ch == '\n');
  result.new_tag = tag_table.look_up(line_buffer);
  *rule_ptr = result;
  return(1);
}

void apply_rule_to_corpus(rule_type rule) {
  /* Should we do this in two passes, to avoid chaining? */
  /* Just work through corpus, calling match_rule at each site */
  int word_num;
  word_rec *word_ptr;
  for (word_num=0; word_num<combined_word_count; word_num++) {
    word_ptr = (*text_ptr)[word_num];
    if (rule.new_tag != word_ptr->cur_tag &&
	match_rule(rule, word_num))
      word_ptr->new_tag = rule.new_tag;
    else
      word_ptr->new_tag = 0;
  }
  for (word_num=0; word_num<combined_word_count; word_num++) {
    word_ptr = (*text_ptr)[word_num];
    if (word_ptr->new_tag)
      word_ptr->cur_tag = word_ptr->new_tag;
  }
}

void apply_rules() {
  rule_type rule;
  open_rules_file();
  pass = 0;
  while (!feof(rules_fptr)) {
    if (read_rule_line(&rule)) {
      pass++;
      apply_rule_to_corpus(rule);
    }
  }
  close_rules_file();
}

void print_new_corpus_file() {
  word_rec this_word;
  for (int word_num=0; word_num<combined_word_count; word_num++) {
    this_word = *(*text_ptr)[word_num];
    printf("%s %s %s\n",
	    word_table.string(this_word.word),
	    pos_tag_table.string(this_word.pos_tag),
	    tag_table.string(this_word.cur_tag));
    /*
    for (int i=0; i<this_word.poss_tags_count; i++)
      if (this_word.poss_tags[i] != this_word.cur_tag)
	printf(" %s", tag_table.string(this_word.poss_tags[i]));
    printf("\n");
    */
    if (this_word.right == 0)
      printf("\n");
  }
}
