#!/bin/bash
##!/bin/sh
#  $0   与键入的命令行一样，包含脚本文件名
#	 $1,$2,……$9  分别包含第一个到第九个命令行参数
#	 $#   包含命令行参数的个数
#	 $@   包含所有命令行参数：“$1,$2,……$9”
#	 $?   包含前一个命令的退出状态
#	 $*   包含所有命令行参数：“$1,$2,……$9”
#	 $$   包含正在执行进程的ID号

# example for read one
# \c 是sh中的转移单词
#echo "Input your name: \c"
echo "Input your name: "
read  username
echo "Your name is $username"


# example for read two
#echo "Input date with format yyyy mm dd: \c"
echo "Input date with format yyyy mm dd: "
read year month day
echo "Today is $year/$month/$day, right?"
echo "Press enter to confirm and continue"
#echo "Press enter to confirm and continue\c"
read answer
echo "I konw the date, bye!"

# example for expr
# 反斜线去掉*号的元字符含义
# 反撇号引用命令的运行结果
read num
sum=`expr $num \* 6`
echo "$num * 6 = $sum"
