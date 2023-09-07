#!/bin/bash

echo -e "请输入：\c"

read A

case $A in
  gao | Gao | g | G)
    echo "棒"
    ;;
  di | Di | d | D)
    echo "低"
    ;;
  *)
    echo "error"
    ;;
esac