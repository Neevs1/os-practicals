#!/bin/bash
echo "Welcome to address book";
records="records.txt";
input(){
 echo "Enter name of the person";
 read name;
 echo "Enter phone number";
 read num;
 echo "Enter address";
 read address;
 echo -n "Enter Pincode ";
 read pincode;
 
 index=$(wc -l < "$records");
 index=$((index-1))
 record=($index "|" $name "|" $num "|" $address "|" $pincode);
 echo "Entered record to file"
 echo "${record[@]}">>records.txt;
}

output(){
 cat records.txt;
}

search(){
 echo -n "Enter index of specific record ";
 read index;
 index=$((index+2));
 head -n $index records.txt | tail -1;
}

echo "Please enter required operation";
echo "1. Add a record";
echo "2. View all records";
echo "3. Search records";
read choice;

case $choice in 
  1)
  input
  ;;
  2)
  output
  ;;
  3)
  search
  ;;
  *)
  echo "Illegal command specified"
  ;;
esac


