#! /usr/bin/perl

# baseNP chunker, v. 1
# Copyright (C) 1995 University of Pennsylvania
# See file README_chunker for further information.

# reads a chunker output file
# writes it out in sentence-per-line form
# with brackets around baseNPs

$in_basenp = 0;
$line_begin = 1;

while (<>) {
    chop;
    if ($_ eq "") {
	if ($in_basenp) {
	    print "]";
	}
	print "\n";
	$in_basenp = 0;
	$line_begin = 1;
    }
    else {
	($word, $pos_tag, $tag) = split;
	if ($in_basenp) {
	    if ($tag eq "B") {
		print " ] [";
	    }
	    elsif ($tag eq "O") {
		print " ]";
		$in_basenp = 0;
	    }
	}
	else {
	    if ($tag eq "B" || $tag eq "I") {
		print " " unless $line_begin;
		$line_begin = 0;
		print "[";
		$in_basenp = 1;
	    }
	    # for "O" tag, just keep going
	}
	print " " unless $line_begin;
	$line_begin = 0;
	print "$word/$pos_tag";
    }
}
