echo "Enter First Element : "
read a
echo "Enter Second Element : "
read b
echo "Enter Third Element : "
read c
max=$a
if [ $b -gt $max ];
then
max=$b
fi
if [ $c -gt $max ];
then
max=$c
fi
echo "$max is the Largest"
