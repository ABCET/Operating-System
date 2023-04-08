read -p "Enter decimal number" d
a=()
b=$d
i=0
while [ $d -gt 0 ]
do
    a[i]=$((d%2))
    d=$((d/2))
    i=$((i+1))
done
echo -n "Binary of $b is "
for (( j= $i-1;j>=0;j-- ))
do
    echo -n "${a[$j]}"
done
echo ""
a=()
i=0
d=$b
while [ $d -gt 0 ]
do
    r=$((d%16))
    if [ $r -lt 10 ]
    then
        a[i]=$r
    else
        case $r in
            10) a[i]="A";;
            11) a[i]="B";;
            12) a[i]="C";;
            13) a[i]="D";;
            14) a[i]="E";;
            15) a[i]="F";;
        esac
    fi
    d=$((d/16))
    i=$((i+1))
done
echo -n "Hexadecimal of $b is "
for (( j= $i-1;j>=0;j-- ))
do
    echo -n "${a[$j]}"
done
echo ""
