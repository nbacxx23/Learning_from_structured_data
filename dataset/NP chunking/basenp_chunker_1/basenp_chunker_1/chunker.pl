#! /usr/bin/perl

## After unpacking the tar file, 
## set the following variable to the pathname 
## of the directory containing this file.
$chunk_dir = "/usr/me/basenp_chunker";

# baseNP chunker, v. 1
# Copyright (C) 1995 University of Pennsylvania
# See file README_chunker for further information.

# This script takes as standard input text tagged by Eric Brill's 
# RULE_BASED_TAGGER_V1.14 and outputs the same text with brackets 
# added around those consituents identified as "baseNPs" by the 
# transformation-based learning approach described in 
# Ramshaw & Marcus 95 (http://xxx.lanl.gov/e-print/cmp-lg/9505040).

# The rules currently applied were learned by training on 200K words
# of Wall St. Journal text, using as correct answers for the training
# baseNP consituents derived algorithmically from the Penn Treebank
# parses of the texts.

$silent = 1;
$clean_up_after = 1;

# copy the input to a temp file, since we need it more than once
open(TEMP_INPUT, ">$chunk_dir/tmp/input_raw");
while (<>) {
    print TEMP_INPUT;
}
close(TEMP_INPUT);

# The chunker needs a list of all the words in the input and rules.
print STDERR "Deriving wordlist...\n" unless $silent;
$status = system "$chunk_dir/perl/corpus_wordlist.pl $chunk_dir/tmp/input_raw > $chunk_dir/tmp/corpus_words";
die "Bailing out due to errors" if $status != 0;
$status = system "$chunk_dir/perl/merge_wordlists.pl $chunk_dir/tmp/corpus_words $chunk_dir/data/rule_words > $chunk_dir/tmp/wordlist";
die "Bailing out due to errors" if $status != 0;

# The input needs to be in word-per-line form, 
# with an initial baseline guess chunk tag supplied.
print STDERR "Putting input into proper form...\n" unless $silent;
$status = system "$chunk_dir/perl/format_input.pl $chunk_dir/data/chunk_tags $chunk_dir/data/pos_tag_dict < $chunk_dir/tmp/input_raw > $chunk_dir/tmp/input";
die "Bailing out due to errors" if $status != 0;

# Now we can run the chunker.
print STDERR "Running the chunker...\n" unless $silent;
$status = system "$chunk_dir/code/chunker $chunk_dir/tmp/wordlist $chunk_dir/data/pos_tags $chunk_dir/data/chunk_tags $chunk_dir/data/rules < $chunk_dir/tmp/input > $chunk_dir/tmp/output_raw";
die "Bailing out due to errors" if $status != 0;

# Put the output back into Brill-like form, with brackets.
print STDERR "Postprocessing output...\n" unless $silent;
$status = system "$chunk_dir/perl/format_output.pl $chunk_dir/tmp/output_raw > $chunk_dir/tmp/output";
die "Bailing out due to errors" if $status != 0;

# And ship it off to standard output.
open(TEMP_OUTPUT, "$chunk_dir/tmp/output");
while(<TEMP_OUTPUT>) {
    print;
}
close(TEMP_OUTPUT);

if ($clean_up_after) {
    unlink "$chunk_dir/tmp/corpus_words";
    unlink "$chunk_dir/tmp/input_raw";
    unlink "$chunk_dir/tmp/input";
    unlink "$chunk_dir/tmp/wordlist";
    unlink "$chunk_dir/tmp/output_raw";
    unlink "$chunk_dir/tmp/output";
}


