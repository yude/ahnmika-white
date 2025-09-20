#! /usr/bin/env awk -f

BEGIN {
	srand()
}

{
	randNum = 100 + int(rand() * 900)
	print "白って" randNum "色あんねん"
}

END {
	print NR "人のアンミカ"
}
