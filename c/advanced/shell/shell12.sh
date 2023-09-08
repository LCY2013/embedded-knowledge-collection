#!/bin/bash
# ./shell12.sh file  6

# The statement for while
if [ $# = 2 ]
then
  loop=$2  # 根据命令行的第二个参数来确定循环的次数
else
  loop=5
fi
i=1
while [ $i -lt $loop ]; do
    > $1$i #建立以第一个参数指定的文件名前缀，例如以“file”开头, 变量i的值结尾的空文件名. 参见命令cmd  >  file

    i=`expr $i + 1`
done
