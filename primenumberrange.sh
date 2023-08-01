#!/bin/bash 
  //chmod +x program.sh
  // ./program.sh
 echo "Enter the Numbers for The Range: " 
 read m 
 read n
 echo "The Prime Numbers between the given range are:" 
 echo 
  
 flag=0 
 for ((i=$m; i<=$n; i++)) 
 do 
     flag=0 
     for ((j=2; j<=i/2; j++)) 
     do 
         if [ $((i%j)) -eq 0 ]; then 
             flag=1 
             break 
         fi 
     done 
     if [ $flag -eq 0 ]; then 
         echo -ne "$i " 
     fi 
 done
