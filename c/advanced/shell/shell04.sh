#!/bin/bash
# The statement of if...then...else..ffi
if  [ -d $1 ]
then
  echo "$1 is a directory"
  exit #退出当前shell程序
else
  if [ -f $1 ]
  then
    echo "$1 is a common file"
  else
    echo "unknown"
  fi
fi

