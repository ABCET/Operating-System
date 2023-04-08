read -p "Enter the file name: " file
while read line 
do
    echo "$line"
    fields=($line)
    roll=${fields[0]}
    sub1=${fields[1]}
    sub2=${fields[2]}
    sub3=${fields[3]}
    if (( sub1 >= 50 && sub2 >= 50 && sub3 >= 50 ))
    then
        status="pass"
    else
        status="fail"
    fi
    echo "$roll $status"
done < $file
