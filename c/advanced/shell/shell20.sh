#! /bin/bash

I=0

while true
do
	I=`expr $I + 1`
	echo -n "input : "
	read S
	case `expr $S / 10` in
		10|9)
			echo "A"
			;;
		6|7|8)
			echo "B"
			;;
		*)
			echo "C"
			;;
	esac
done
