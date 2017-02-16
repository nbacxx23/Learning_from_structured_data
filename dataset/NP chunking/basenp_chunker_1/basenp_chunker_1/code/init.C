// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#include "defns.H"
#include "templ_enum.H"
#include "types.H"
#include "extern.H"
#include "templates.H"

void initialize_text_word_recs () {
  for (int i=0; i<max_words; i++) {
    (*text_ptr)[i] = new word_rec;
    DEBUG_ASSERT((*text_ptr)[i] != NULL);
  }
}

int trainp(int sentence) {
  return (sentence < train_sentence_count);
}

void clear_tag_string (tag_string_type tag_string) {
  for (int i=0; i<max_tag_width; i++) 
    tag_string[i] = '\0';
}

void clear_pos_tag_string (pos_tag_string_type pos_tag_string) {
  for (int i=0; i<max_pos_tag_width; i++) 
    pos_tag_string[i] = '\0';
}

void clear_word_string (word_string_type word_string) {
  for (int i=0; i<max_word_width; i++) 
    word_string[i] = '\0';
}


/*
**  READ TABLES CODE
*/

tag_num_type look_up_tag (tag_string_type tag_string) {
  int i=tag_table.look_up(tag_string);
  if (i==-1) {
    fprintf(stderr, "Error!  Tag %s not found in tag table.\n", tag_string);
    DEBUG_ASSERT(i!=-1);
  }
  return((tag_num_type) i);
}

pos_tag_num_type look_up_pos_tag (pos_tag_string_type pos_tag_string) {
  int i=pos_tag_table.look_up(pos_tag_string);
  if (i==-1) {
    fprintf(stderr, "Error!  Tag %s not found in pos tag table.\n", pos_tag_string);
    DEBUG_ASSERT(i!=-1);
  }
  return((pos_tag_num_type) i);
}

word_num_type look_up_word (word_string_type word_string) {
  int i=word_table.look_up(word_string);
  if (i==-1) {
    fprintf(stderr, "Error!  Word %s not found in word table.\n", word_string);
    DEBUG_ASSERT(i!=-1);
  }
  return((word_num_type) i);
}

void read_all_tags_file() {
  FILE *fptr;
  if ((fptr = fopen(all_tags_file, "r")) == NULL)
    printf("All_tags data file could not be opened.\n");
  else {
    tag_count = 0;
    while (!feof(fptr)) {
      fscanf(fptr, "%s", line_buffer);
      if (!feof(fptr)) {
	tag_table.add_string(line_buffer);
	tag_count++;
      }
    }
    end_sentence_tag_num = tag_table.add_string(end_sentence_tag);
    tag_count++;
  }
  fclose(fptr);
}

void read_all_pos_tags_file() {
  FILE *fptr;
  if ((fptr = fopen(all_pos_tags_file, "r")) == NULL)
    printf("All_pos_tags data file could not be opened.\n");
  else {
    pos_tag_count = 0;
    while (!feof(fptr)) {
      fscanf(fptr, "%s", line_buffer);
      if (!feof(fptr)) {
	pos_tag_table.add_string(line_buffer);
	pos_tag_count++;
      }
    }
    end_sentence_pos_tag_num = pos_tag_table.add_string(end_sentence_pos_tag);
    pos_tag_count++;
  }
  fclose(fptr);
}

void read_all_words_file() {
  FILE *fptr;
  if ((fptr = fopen(all_words_file, "r")) == NULL)
    printf("All_words data file could not be opened.\n");
  else {
    dict_word_count = 0;
    while (!feof(fptr)) {
      fscanf(fptr, "%s", line_buffer);
      if (!feof(fptr)) {
	word_table.add_string(line_buffer);
	dict_word_count++;
      }
    }
    end_sentence_word_num = word_table.add_string(end_sentence_word);
    dict_word_count++;
  }
  fclose(fptr);
}

char *get_tag(int index) {
  return(tag_table.string(index));
}

char *get_pos_tag(int index) {
  return(pos_tag_table.string(index));
}

char *get_word(int index) {
  return(word_table.string(index));
}

char *get_templ(int index) {
  return(templ_table.string(index));
}

/*
**  READ CORPUS CODE
*/

void read_word(char *line_buffer, int sentence_num, int word_num, int train) {
  // reads correct tags into 0, alternatives into 1 and following
  int tag_num, i;
  tag_string_type tag_string;
  pos_tag_string_type pos_tag_string;
  word_string_type word_string;
  tag_num_type tag_id;
  pos_tag_num_type pos_tag_id;
  word_num_type word_id;
  char *buf_tail;
  word_rec *word_rec_ptr = (*text_ptr)[s_ind[sentence_num].start+word_num];
  buf_tail = line_buffer;

  // read word
  for (i=0; *(buf_tail + i) != ' ' && *(buf_tail + i) != '\n'; i++) ;
  clear_word_string(word_string);
  strncpy(word_string, buf_tail, i);
  word_id = look_up_word(word_string);
  DEBUG_ASSERT(word_id != 0);
  word_rec_ptr->word = word_id;
  buf_tail += i+1;

  // read pos tag
  for (i=0; *(buf_tail + i) != ' ' && *(buf_tail + i) != '\n'; i++) ;
  clear_pos_tag_string(pos_tag_string);
  strncpy(pos_tag_string, buf_tail, i);
  pos_tag_id = look_up_pos_tag(pos_tag_string);
  DEBUG_ASSERT(pos_tag_id != 0);
  word_rec_ptr->pos_tag = pos_tag_id;
  buf_tail += i+1;
  
/*
  // read correct tag
  for (i=0; *(buf_tail + i) != ' ' && *(buf_tail + i) != '\n'; i++) ;
  clear_tag_string(tag_string);
  strncpy(tag_string, buf_tail, i);
  tag_id = look_up_tag(tag_string);
  DEBUG_ASSERT(tag_id != 0);
  word_rec_ptr->corr_tag = tag_id;
  buf_tail += i+1;
*/

  // read baseline and other possible tags
  tag_num=0;
  while (*buf_tail != '\0' && *buf_tail != '\n') {
    for (i=0; *(buf_tail + i) != ' ' && *(buf_tail + i) != '\n'; i++) ;
    clear_tag_string(tag_string);
    strncpy(tag_string, buf_tail, i);
    tag_id = look_up_tag(tag_string);
    word_rec_ptr->poss_tags[tag_num] = tag_id;
    // for now, use the first poss_tag as the cur_tag 
    if (tag_num == 0) {
      word_rec_ptr->cur_tag = tag_id;
    }
    DEBUG_ASSERT(tag_id != 0);
    tag_num++;
    buf_tail += i+1;
  }
  if (train) {
    train_total_count++;
    if (word_rec_ptr->cur_tag == word_rec_ptr->corr_tag)
      train_correct_count++;
  }
  else {
    test_total_count++;
    if (word_rec_ptr->cur_tag == word_rec_ptr->corr_tag)
      test_correct_count++;
  }
  if (tag_num > max_tags_per_word) 
    fprintf(stderr, "Error! Too many tags for a word in sentence %d\n", sentence_num);
  word_rec_ptr->poss_tags_count=tag_num;
  next_word_slot++;
}

int read_sentence(int sentence_num, int train) {
  int word_num = 0;
  fgets(line_buffer, bufsize, stdin);
  if (!feof(stdin)) {
    s_ind[sentence_num].start = next_word_slot;
    while (line_buffer[0] != '\n') {
      read_word(line_buffer, sentence_num, word_num, train);
      word_num++;
      fgets(line_buffer, bufsize, stdin);
    }
    if (word_num >= max_sentence_length-1) 
      fprintf(stderr, "Error! Too many words in sentence %d\n", sentence_num);
    s_ind[sentence_num].count = word_num;
    if (train)
      train_word_count+= word_num;
    else
      test_word_count+=word_num;
    return (1);
  }
  else
    return(0);
}

void read_test_corpus() {
  int sentence_num=train_sentence_count;
  test_total_count=0;
  test_correct_count=0;
  while (!feof(stdin)) {
    if (read_sentence(sentence_num, 0))
      sentence_num++;
    DEBUG_ASSERT(sentence_num <= max_sentences);
  }
  test_sentence_count = sentence_num - train_sentence_count;
  test_percent_correct = (100.0 * test_correct_count) / test_total_count;
}

void reset_percent_correct () {
  train_percent_correct = (100.0 * train_correct_count) / train_total_count;
  test_percent_correct = (100.0 * test_correct_count) / test_total_count;
}

void set_up_sentence_end_counts() {
  /* Process corpus by sentences, filling in left and right counts */
  locus_class locus;
  int count;
  for (locus.sent=0; locus.sent<total_sentence_count; locus.sent++) {
    count = s_ind[locus.sent].count;
    for (locus.word=0; locus.word<count; locus.word++) {
      (*text_ptr)[s_ind[locus.sent].start+locus.word]->left = locus.word;      
      (*text_ptr)[s_ind[locus.sent].start+locus.word]->right = (count-1)-locus.word;
    }
  }  
}

void set_up(int apply_rules) {

  train_word_count=0;
  test_word_count=0;
  combined_word_count=0;

  // the following casts should not be necessary,
  // but this version of g++ seems to require them
  text_ptr = (word_rec_ptr_type (*)[max_words]) new word_rec_ptr_type[max_words];
  initialize_text_word_recs();

  init_templ_table();
  init_templ_arg_type_array();

  read_all_tags_file();
  read_all_pos_tags_file();
  read_all_words_file();

  next_word_slot = 0;
  train_word_count = 0;
  train_sentence_count = 0;

  read_test_corpus();
  combined_word_count = train_word_count + test_word_count;
  total_sentence_count = train_sentence_count + test_sentence_count;
  set_up_sentence_end_counts();

}


