#! /bin/bash

if [ $# -eq 0 ]
then
	echo  "$0 filename"
	exit
fi

if ! [ -e $1 ]
then
	echo "$1 not exist"
	exit
fi

if [ -L $1 ]
then
	echo "$1 是链接文件"
elif [  -d $1 ]
then
	echo "d"
elif [ -f $1 ]
then
	echo "-"
elif [ -b $1 ]
then
	echo "b"
elif [ -c $1 ]
then
	echo "c"
elif [ -S $1 ]
then
	echo "S"
else
	echo "p"
fi