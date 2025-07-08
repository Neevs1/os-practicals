echo -n "Enter a number = "
read n

c=$n
rev=0

while [ $n -gt 0 ] 
do 
	rem=$((n%10))
	rev=$((rev*10+rem))
	n=$((n/10))
done

if [ $c -eq $rev ];
then
	echo "$c is palindrome"
else
	echo "$c is not a palindrome"
fi
