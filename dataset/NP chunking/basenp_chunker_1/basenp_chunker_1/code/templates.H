// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

void init_templ_table();

void init_templ_arg_type_array();

int templ_arg_count(templ_type templ);
int templ_alt_count(templ_type templ);

arg_type_enum find_templ_arg_type(templ_type templ, int num);

int match_rule(const rule_type &rule, int word_num);

int match_rule_static(const rule_type &rule, int word_num);

void templ_args(templ_type templ, int word_num, templ_arg_type args[max_rule_args], int alt);
