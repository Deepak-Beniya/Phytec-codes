#!/bin/bash
#expr is command for expression
# \* is for multiplication 
echo "Arithmetic Operation"
read a
read b
c=`expr $a + $b`
echo "Addition of two numbers are $c"
c=`expr $a - $b`
echo "Subtractions of two numbers are $c"
c=`expr $a \* $b`
echo "Multiplication of two numbers are $c"
c=`expr $a / $b`
echo "Division of two numbers are $c"
c=`expr $a % $b`
echo "Modulo of two numbers are $c"

