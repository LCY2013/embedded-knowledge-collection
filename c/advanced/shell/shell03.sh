#!/bin/bash
#The statement of if...then...fi
# test param is file
echo "\$0=$0"
echo "\$?=$?"
echo "\$\$=$$"
echo "\$*=$*"
echo "\$@=$@"
echo "\$#=$#"
if [  -f  $1  ]
then
  echo "File $1 exists"
fi
if [  -d  $HOME/$1  ]
then
  echo "File $1 is a directory"
fi
