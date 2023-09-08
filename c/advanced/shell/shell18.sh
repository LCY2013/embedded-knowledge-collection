#! /bin/bash

i=1
sum=0

while [ $i -le 10 ]
do
	sum=`expr $sum + $i`
	i=`expr $i + 1`
done


echo "i = $i  sum = $sum"
