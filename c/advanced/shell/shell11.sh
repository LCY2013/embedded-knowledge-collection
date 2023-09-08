#!/bin/bash
# ./shell11.sh [filename]

#The statement of for...do...done
if [ ! -d $HOME/backup ]
then
  mkdir $HOME/backup
fi
flist=`ls`
for file in $flist
do
    if [ $# = 1 ]
    then
        if [ $1 = $file ]
        then
          echo "$file found"; exit
        fi
    else
        cp $file $HOME/backup
        echo "$file copied"
    fi
done
echo ***Backup Completed***
