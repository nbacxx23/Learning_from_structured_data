// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#include "defns.H"
#include "templ_enum.H"
#include "types.H"
#include "init.H"
#include "rules.H"
#include "apply.H"

// these vars used in some of the inline class methods
// train_sentence_count is set high initially, 
// so train sentences will be treated as such on the first pass
int train_sentence_count = 1000000;
int test_sentence_count;
int total_sentence_count;

void print_indent(int ind);

/*
**  GLOBAL VARIABLES
*/ 

char line_buffer[bufsize];

char all_words_file[bufsize];
char all_pos_tags_file[bufsize];
char all_tags_file[bufsize];
char apply_rules_file[bufsize];

sentence_index_entry_type s_ind[max_sentences];
int next_word_slot;

//word_rec_ptr_type text[max_words];
text_type *text_ptr;

//template_type templates[max_templates];
int template_count;

int found_rule_count, prev_found_rule_count, active_rule_count, inactive_rule_count;
int pos_scoring_events;
int neg_scoring_events;
int side_scoring_events;

int test_set_pos_changes;
int test_set_neg_changes;
int test_set_side_changes;

tag_string_type all_tags[max_tags];
double all_tag_weights[max_tags];
int all_tag_count;

int end_sentence_tag_num;
int end_sentence_pos_tag_num;
int end_sentence_word_num;

int train_total_count;
int test_total_count;
int train_correct_count;
int test_correct_count;
double train_percent_correct;
double test_percent_correct;

int change_count, benefit_count;

int train_changes_scheduled, train_changes_made;
int test_changes_scheduled, test_changes_made;

int train_word_count;
int test_word_count;
int combined_word_count;

int find_rule_compare_count;

int correct_tag_count[max_tags];

int new_rules_count;
//rule_list_class new_rule_list;

int pass;

sorted_string_table tag_table (max_tags, max_tags * max_tag_width);
sorted_string_table pos_tag_table (max_pos_tags, max_pos_tags * max_pos_tag_width);
sorted_string_table word_table (max_dict_words, max_dict_chars);
unsorted_string_table templ_table (max_templates, max_template_chars);

pos_tag_num_type pos_tag_class[max_pos_tags];
pos_tag_num_type first_pos_class_tag_num, last_pos_class_tag_num;

arg_type_enum templ_arg_type_array[max_templates][max_rule_args];

int dict_word_count=0;
int pos_tag_count=0;
int tag_count=0;

/*
**   MAIN
*/

int main(int argc, char *argv[]) {
  if (argc != 5)
    printf("Usage: chunker WORDLIST POSTAGS CHUNKTAGS RULES < CORPUS > CORPUS_CHUNKED\n");
  else {
    strcpy(all_words_file, argv[1]);
    strcpy(all_pos_tags_file, argv[2]);
    strcpy(all_tags_file, argv[3]);
    strcpy(apply_rules_file, argv[4]);
    set_up(1);
    apply_rules();
    print_new_corpus_file();
  }
}
