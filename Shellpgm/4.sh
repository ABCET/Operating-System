read -p "Enter 1st number " a
read -p "Enter 2nd number " b
read -p "Enter 3rd number " c
if [ $a -le $b ]
then
if [ $a -le $c ]
then
echo "smallest no : $a"
else
echo "smallest no : $c"
fi
else
if [ $b -le $c ]
then
echo "smallest no : $b"
else
echo "smallest no : $c"
fi
fi