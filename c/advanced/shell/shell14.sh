#! /bin/bash

i=1
sum=0

while [ $i -le 10 ]
do
	sum=`expr $sum + $i`
	i=`expr $i + 1`
	if [ $i -eq 3 ]
	then
		break
	fi

done


echo "i = $i  sum = $sum"
