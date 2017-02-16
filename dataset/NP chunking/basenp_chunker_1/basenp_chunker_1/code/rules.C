// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#include "defns.H"
#include "templ_enum.H"
#include "types.H"
#include "extern.H"
#include "init.H"
#include "templates.H"

int in_sentence(int word_num, int offset) {
  if (offset==0)
    return(1);
  else if (offset > 0)
    return(offset <= (*text_ptr)[word_num]->right);
  else
    return((-1 * offset) <= (*text_ptr)[word_num]->left);
}

tag_num_type word_tag (int word_num, int offset) {
  if (in_sentence(word_num, offset))
    return((*text_ptr)[word_num+offset]->cur_tag);
  else
    return(end_sentence_tag_num);
}

pos_tag_num_type word_pos_tag (int word_num, int offset, int cl=0) {
  if (in_sentence(word_num, offset)) {
    pos_tag_num_type pos_tag = (*text_ptr)[word_num+offset]->pos_tag;
    if (cl)
      return(pos_tag_class[pos_tag]);
    else
      return(pos_tag);
  }
  else
    return(end_sentence_pos_tag_num);
}

word_num_type word_lex_tag (int word_num, int offset) {
  if (in_sentence(word_num, offset))
    return((*text_ptr)[word_num+offset]->word);
  else
    return(end_sentence_word_num);
}

arg_type_enum find_templ_arg_type(templ_type templ, int num) {
  return (templ_arg_type_array[(int) templ][num]);
}

int same_rule (const rule_type &rule1, const rule_type &rule2) {
  if (rule1.arg_count != rule2.arg_count)
    return(0);
  if (rule1.templ != rule2.templ)
    return(0);
  for (int i=0; i<rule1.arg_count; i++) 
    if (rule1.args[i] != rule2.args[i])
      return(0);
  if (rule1.new_tag != rule2.new_tag)
    return(0);
  return (1);
}


