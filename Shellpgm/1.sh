for name in $@
do
echo "file name:"$name
tr [:lower:] [:upper:] < $name
echo " "
done
