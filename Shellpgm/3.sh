read -p "Basic pay:" b
if [ $b -lt 1500 ]
then
g=$(($(($b/10))+$((9*$b/10))+$b))
else
g=$((500+$((98*$b/100))+$b))
fi
echo "gross salary : $g"