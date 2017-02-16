// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

void initialize_text_word_recs ();

int trainp(int sentence);

void clear_tag_string (tag_string_type tag_string);

tag_num_type look_up_tag (tag_string_type tag_string);
pos_tag_num_type look_up_pos_tag (pos_tag_string_type pos_tag_string);
word_num_type look_up_word (word_string_type word_string);
void reset_percent_correct ();

void read_all_tags_file();

char *get_tag(int index);
char *get_pos_tag(int index);
char *get_word(int index);
char *get_templ(int index);

void read_word(char *line_buffer, int sentence_num, int word_num, int train);

int read_sentence(FILE *fptr, int sentence_num, int train);

void read_train_corpus();

void read_test_corpus();

void read_all_pos_tags_file();

void read_all_words_file();

void set_up(int apply_rules);
