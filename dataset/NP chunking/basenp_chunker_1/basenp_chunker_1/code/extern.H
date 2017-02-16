// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

/*
**  GLOBAL VARIABLES
*/ 

extern char line_buffer[bufsize];

extern sentence_index_entry_type s_ind[max_sentences];
extern int next_word_slot;

extern text_type *text_ptr;

//extern template_type templates[max_templates];
extern int template_count;

extern int found_rule_count, prev_found_rule_count, active_rule_count, inactive_rule_count;
extern int pos_scoring_events;
extern int neg_scoring_events;
extern int side_scoring_events;

extern int test_set_pos_changes;
extern int test_set_neg_changes;
extern int test_set_side_changes;

extern tag_string_type all_tags[max_tags];
extern double all_tag_weights[max_tags];
extern int all_tag_count;

extern int train_total_count;
extern int test_total_count;
extern int train_correct_count;
extern int test_correct_count;
extern double train_percent_correct;
extern double test_percent_correct;
extern int change_count, benefit_count;

extern int train_changes_scheduled, train_changes_made;
extern int test_changes_scheduled, test_changes_made;

extern int new_rules_count;
extern int rules_found;

extern int pass;

extern int train_sentence_count;
extern int test_sentence_count;
extern int total_sentence_count;

extern char all_words_file[bufsize];
extern char all_pos_tags_file[bufsize];
extern char all_tags_file[bufsize];
extern char apply_rules_file[bufsize];

extern sorted_string_table tag_table;
extern sorted_string_table pos_tag_table;
extern sorted_string_table word_table;
extern unsorted_string_table templ_table;

extern pos_tag_num_type pos_tag_class[max_pos_tags];
extern pos_tag_num_type first_pos_class_tag_num, last_pos_class_tag_num;

extern arg_type_enum templ_arg_type_array[max_templates][max_rule_args];

extern int dict_word_count;
extern int pos_tag_count;
extern int tag_count;

extern int end_sentence_tag_num;
extern int end_sentence_pos_tag_num;
extern int end_sentence_word_num;

extern int train_word_count;
extern int test_word_count;
extern int combined_word_count;

extern int find_rule_compare_count;
