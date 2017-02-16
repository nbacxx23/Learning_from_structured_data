// BaseNP Chunker, v. 1
// Copyright (C) 1995 University of Pennsylvania
// See file README_chunker for further information.

#include "defns.H"
#include "templ_enum.H"
#include "types.H"
#include "extern.H"

// Here are the method definitions for the classes in types.i

int locus_class::trainp() {
  return(sent < train_sentence_count);
}

string_table::string_table(int max_count, int max_chars) {
  ind_max = max_count;
  char_max = max_chars;
  str = new char[max_chars];
  ind = new int[max_count];
  // index 0 reserved to indicate lookup failure 
  next_ind = 1;
  next_str = 0;
}

int string_table::add_string_at_end(const char* st) {
  int len = strlen(st);
  int here=next_ind;
  ind[next_ind] = next_str;
  strcpy(&str[next_str], st);
  next_str += len + 1;
  DEBUG_ASSERT(next_str < char_max);
  next_ind++;
  DEBUG_ASSERT(next_ind < ind_max);
  return(here);
}

int unsorted_string_table::add_string(const char* st) {
  return(this->add_string_at_end(st));
}

int sorted_string_table::add_string(const char* st) {
  this->add_string_at_end(st);
  /* if not in correct position at the end, find the first earlier string
     that is less than it */
  /* NOTE:  position 0 is unique, and no string will sort back that far */
  int added=next_ind-1;
  int here=added;
  for ( ; here > 1 && strcmp(&str[ind[here-1]], &str[ind[added]]) > 0 ; here--) ;
  if (here < added) {
    int added_str = ind[added];
    for (int i=added; i>here; i--)
      ind[i] = ind[i-1];
    ind[here] = added_str;
  }
  return(here);
}

int unsorted_string_table::look_up(const char* st) {
  for (int i = 1; i<=next_ind-1; i++) {
    int cmp = strcmp(st, &str[ind[i]]);
    if (cmp==0)
      return(i);
  }
  return(0);
}

int sorted_string_table::look_up(const char* st) {
  int low=1;
  int high=next_ind-1;
  
  for ( ; low<=high ; ) {
    int mid = (low+high)/2;
    int cmp = strcmp(st, &str[ind[mid]]);
    if (cmp==0)
      return(mid);
    else if (cmp>0)
      low = mid+1;
    else
      high = mid-1;
  }
  return(0);
}
