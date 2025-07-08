for (( i=0; i<=5; i++ ))

do
for (( j=0; j<=5; i++))
do
 if test $i -ne $j
 then echo -n " "
 else echo -n "*"
 fi;
done
echo ""
done