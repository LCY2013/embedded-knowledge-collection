#!/bin/bash
# ./shell13.sh 整数 整数 整数 ...
if [ $# = 0 ]
then
  echo "Numeric arguments required"
  exit
fi
if [ $# -gt 10 ]
then
  echo "Only ten arguments allowed"
  exit
fi
for number
do
  count=`expr $number % 2`
  if [ $count -eq 1 ]
  then
    continue
  else
    output="$output $number"
  fi
done
echo "Even numbers: $output "
