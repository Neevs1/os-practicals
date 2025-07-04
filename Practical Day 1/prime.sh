
echo "Enter a number";
read num;
for i in $(seq 2 $((num-1)));
do 
 if [ $((num % i)) -eq 0 ];
 then
  declare -i flag=1;
  echo "Composite number";
  break;
 fi;
done
if [ $((flag)) -ne 1 ];
then
 echo "Prime number";
fi;
   
