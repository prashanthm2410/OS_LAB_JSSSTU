echo "Enter the Number of Elements in a Array"
read n
declare -A x
echo "Enter the Array Elements"
for((i=0;i<$n;i++))
do
	read x[$i]
done
max=${x[0]}
for((i=1;i<$n;i++))
do
	if [ ${x[$i]} -gt $max ];
	then
	max=${x[$i]}
	fi
done
