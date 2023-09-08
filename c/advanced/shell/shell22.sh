#!/bin/bash

check_user() { # 查找已登录的指定用户
  user=`who | grep $1 | wc -l`
    if [ $user -eq 0 ]
    then
      return 0 # 未找到指定用户
    else
      return 1 # 找到指定用户
    fi
}

while [ true ]; do # MAIN, Main, main: program begin here
    echo "Input username: \c"
    read uname
    check_user #uname # 调用函数，并传递参数uname
    if [ $? -eq 1 ]  # $?为函数返回值
    then echo "user $uname online"
    else echo "user $uname offline"
    fi
done
