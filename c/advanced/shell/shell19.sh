#! /bin/bash

i=1
sum=0

while [ $i -le 10 ]
do
	if [ $i -eq 3 ]
	then
		i=`expr $i + 1`
		continue
	fi

	sum=`expr $sum + $i`
	i=`expr $i + 1`
	sleep 1


echo "i = $i  sum = $sum"
done
