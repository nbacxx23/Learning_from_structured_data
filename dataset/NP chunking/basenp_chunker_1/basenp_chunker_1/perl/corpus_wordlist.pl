#! /usr/bin/perl

# baseNP chunker, v. 1
# Copyright (C) 1995 University of Pennsylvania
# See file README_chunker for further information.

# Takes tagged corpus file as input.
# Outputs sorted list of words.

while (<>) {
    chop;
    @items = split;
    foreach $item (@items) {
	@parts = split('/', $item);
	# get rid of the tag from the end
	pop(@parts);
	# put the rest (if more than one) back together
	$word = join('/', @parts);
	$words{$word}=1;
    }
}

foreach $word (sort(keys(%words))) {
    print "$word\n";
}
