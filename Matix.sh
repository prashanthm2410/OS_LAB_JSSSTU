declare -A x
declare -A y
declare -A z
echo "Enter The Order of The Matrix"
read m
read n
echo "Enter the elements of the first matrix"
for((i=0;i<$m;i++))
do
    for((j=0;j<$n;j++))
    do
        read x[$i,$j]
    done
done


echo "Enter the elements of the second  matrix"
for((i=0;i<$m;i++))
do
    for((j=0;j<$n;j++))
    do
        read y[$i,$j]
    done
done
echo "The first matrix is :"
for((i=0;i<$m;i++))
do
    for((j=0;j<$n;j++))
    do
        echo -ne " ${x[$i,$j]}  " # -ne or -en will not append a new line in echo
    done
    echo
    echo
done

echo "The second matrix is:"
echo
for((i=0;i<$m;i++))
do
    for((j=0;j<$n;j++))
    do
        echo -ne " ${y[$i,$j]}   "
    done
    echo
done

echo "The resultant matrix is :"
for((i=0;i<$m;i++))
do
    for((j=0;j<$n;j++))
    do
        z[$i,$j]=$((x[$i,$j]+y[$i,$j]))
        echo  -ne " ${z[$i,$j]}  "
    done
    echo
done
