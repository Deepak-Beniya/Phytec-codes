#!/bin/bash
#readonly is a keyword in shell script once it is applyed the value can't be reassigned
var=31
readonly var
#var=40
echo "var => $var"
hello()
{
	echo "Hello Deepak"
}
readonly hello

hello

#hello()
#{
#	echo "Hello World "
#}
hello




