read -p "Enter number" n
r=0
while [ $n -gt 0 ] 
do
r=$((r*10+n%10))
n=$((n/10))
done
echo "Reverse no:$r"
