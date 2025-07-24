#!/bin/bash
echo "Welcome to address book";
records="records.txt";
input(){
 echo "Enter ID number";
 read index;
 if grep -q "$index" records.txt; then
  echo "ID already exists"; return 1;
  
 fi;
 echo "Enter name of the person";
 read name;
 echo "Enter phone number";
 read num;
 case "$num" in
[1-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]) ;;
*) num=0 ; echo "Invalid phone number entered"; return 1;;
 esac
 echo "Enter address";
 read address;
 echo -n "Enter Pincode ";
 read pincode;
 case "$pincode" in
   [1-9][0-9][0-9][0-9][0-9][0-9]) ;;
   *) pincode=0 ; echo "Invalid pincode entered"; return 1;;
esac
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
 if grep -q "$index" records.txt; then
  grep "$index" records.txt;
 else
  echo "Record not found";
 fi;
}

delete(){
   echo -n "Enter index of specific record ";
   read index;
   todel="$(grep "$index" records.txt)";
   touch temp.txt;
   while IFS= read -r line; do
        
        if [ "$line" = "$todel" ]; then
            continue
        fi
      
        echo "$line" >> temp.txt
    done < records.txt
    
   
    mv temp.txt records.txt
    echo "$todel deleted sucessfully!"

}

modify(){
  echo -n "Enter index of specific record ";
  read index;
  todel="$(grep "$index" records.txt)";
   echo "Enter ID number";
  read index;
  echo "Enter name of the person";
  read name;
  echo "Enter phone number";
  read num;
  case "$num" in
[1-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]) ;;
*) num=0 ; echo "Invalid phone number entered"; return 1;;
 esac
  echo "Enter address";
  read address;
  echo -n "Enter Pincode ";
  read pincode;
  case "$pincode" in
   [1-9][0-9][0-9][0-9][0-9][0-9]) ;;
   *) pincode=0 ; echo "Invalid pincode entered"; return 1;;
esac
  
  record=($index "|" $name "|" $num "|" $address "|" $pincode);
  touch temp.txt;
   while IFS= read -r line; do
        
        if [ "$line" = "$todel" ]; then
            continue
        fi
      
        echo "$line" >> temp.txt
    done < records.txt 
   
    mv temp.txt records.txt;
     echo "${record[@]}">>records.txt;
     echo "${record[@]} modified";


}

while true; do
    echo "=============================="
    echo "Please enter required operation"
    echo "1. Add a record"
    echo "2. View all records"
    echo "3. Search records"
    echo "4. Delete a record"
    echo "5. Modify a record"
    echo "0. Exit"
    echo "=============================="
    echo -n "Enter your choice: "
    read choice

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
        4)
            delete
            ;;
        5)
            modify
            ;;
        0)
            echo "Exiting..."
            break   # breaks the while loop
            ;;
        *)
            echo "Illegal command specified"
            ;;
    esac

    echo ""  # blank line for readability
done


