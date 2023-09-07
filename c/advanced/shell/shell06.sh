#!/bin/bash

if [ $# -eq 0 ]
then
  echo "$0 filename"
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
fi

if [ -w $1 ]
then
  echo "$1 是存在且可写"
fi

if [ -r $1 ]
then
  echo "$1 是存在且可读"
fi

if [ -S $1 ]
then
  echo "$1 是套接字文件"
fi

if [ -b $1 ]
then
  echo "$1 是块设备文件"
fi
