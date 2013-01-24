#!/usr/bin/perl -w
use strict;

srand(0);

sub report_line($)
{
	my ($file) = @_;
	my $line = 0;
	open(FILE, "<$file") || die "cannot open $file";
	while (<FILE>) {
		$line++;
		if (/ERROR:/) {
			print "$file:$line\n";
			last;
		}
	}
	close FILE;
}

while (my $file = shift @ARGV) {
	my $reply = int(rand(2));
	report_line($file) if ($reply);
}

0;
