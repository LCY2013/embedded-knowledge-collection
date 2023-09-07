#!/bin/bash

echo -e "请输入：\c"

read A

case $A in
  gao)
    echo "好"
    ;;
  di)
    echo "低"
    ;;
  *)
    echo "error"
    ;;
esac