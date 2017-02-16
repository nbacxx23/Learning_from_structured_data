#! /usr/bin/perl

# baseNP chunker, v. 1
# Copyright (C) 1995 University of Pennsylvania
# See file README_chunker for further information.

die "Usage: format_input.pl CHUNKTAGS POSTAGDICT < CORPUS_POS_TAGGED"
    unless $#ARGV == 1;

# Loads the CHUNKTAGS and POSTAGDICT files

# Then reads a Brill-tagged data file and writes it out
# in the proper input format for the chunker.

open(CHUNKTAGS, $ARGV[0]) || die "Couldn't open CHUNKTAGS file";
while (<CHUNKTAGS>) {
    chop;
    push(@tags, $_);
}

open(DICT, $ARGV[1]) || die "Couldn't open POSTAGDICT file";
while (<DICT>) {
    chop;
    ($pos_tag, $chunk_tag) = split;
    $base_tag{$pos_tag}=$chunk_tag;
}

open(CORPUS, "-");

while (<CORPUS>) {
    chop;
    @items = split;
    foreach $item (@items) {
	@parts = split('/', $item);
	# get rid of the tag from the end
	$pos_tag = pop(@parts);
	# put the rest (if more than one) back together
	$word = join('/', @parts);
	## print STDERR "Word is $word, tag is $pos_tag\n";
	$tag = $base_tag{$pos_tag};
	die "No baseline tag for pos_tag $pos_tag" unless $tag;
	print "$word $pos_tag $tag\n";
	# fill in the other alternatives
	#foreach $poss_tag (@tags) {
	#    print " $poss_tag" unless ($poss_tag eq $tag);
	#}
	#print "\n";
    }
    print "\n";
}

