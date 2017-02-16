// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

int same_rule (const rule_type &rule1, const rule_type &rule2);

void apply_rule(rule_type best_rule);

tag_num_type word_tag (int word_num, int offset);
pos_tag_num_type word_pos_tag (int word_num, int offset, int cl=0);
word_num_type word_lex_tag (int word_num, int offset);
arg_type_enum find_templ_arg_type(templ_type templ, int num);
