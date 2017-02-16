#! /usr/bin/perl

# baseNP chunker, v. 1
# Copyright (C) 1995 University of Pennsylvania
# See file README_chunker for further information.

# Extracts a list of the words used in the RULES file
# for merging with the wordlist from the input text.

while (<>) {
    chop;
    ($template, @args) = split;
    @types = split(/[0-9_]*/, $template);
    foreach $type (@types) {
	$value = shift(@args);
	if ($type eq "W") {
	    $words{$value}=1;
	}
    }
}

foreach $word (sort(keys(%words))) {
    print "$word\n";
}
    
