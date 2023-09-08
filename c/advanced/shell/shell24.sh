#! /bin/bash

function show()
{
	local	A=3         #local  说明是局部变量
	B=4                 #不说明默认是全局变量
}
show
	echo "In show A=$A B=$B"

