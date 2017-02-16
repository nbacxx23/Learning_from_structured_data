#! /usr/bin/perl

# baseNP chunker, v. 1
# Copyright (C) 1995 University of Pennsylvania
# See file README_chunker for further information.

# takes a sequence of wordlists as input
# outputs a single, merged, sorted one

while (<>) {
    chop;
    $words{$_}=1;
}

foreach $word (sort (keys(%words))) {
    print "$word\n";
}
