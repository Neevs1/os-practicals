#!/bin/sh
echo -n "Enter a number = "
read n

c=$n
rev=0

while [ $n -gt 0 ] 
do 
	rem=$((n%10))
	pow=$(echo "$rem^3"|bc)
	rev=$((rev+pow))
	n=$((n/10))
done

if [ $c -eq $rev ];
then
	echo "$c is Armstrong number"
else
	echo "$c is not an Armstrong number"
fi
