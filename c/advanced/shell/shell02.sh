#!/bin/bash
# 测试语句
# test语句可测试三种对象: 字符串、整数、文件属性

# example
echo "Please input answer:"
read answer
# 变量answer的值是否为字符串yes
test  "$answer"  =  "yes"
echo $?
echo "Please input number:"
read num
# 变量num的值是否为整数18
test  $num –eq  18
echo $?
echo "Please input dir:"
# 测试tmp是否为一个目录名
test  -d  tmp
echo $?




