a=("$@")
n=$#
for(( i=$n-1; i>=0; i-- ))
do
echo -n "${a[$i]} "
done