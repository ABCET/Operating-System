for (( i=1; i<=3; i++ ))
do
    for (( j=0; j<=3; j++ ))
    do
        for(( k=0; k<=3; k++ ))
        do
            echo $i$j$k
            c=$((c+1))
        done
    done
done