#! /bin/bash

if [ -d $HOME/lianxi ]
then
	echo "YES"
else
	mkdir $HOME/lianxi
	echo "create backup success"
fi

flist=`ls`
echo "$flist"
for file in $flist
do
	cp $file $HOME/lianxi
	echo "$file if copied"
done

echo "copy done!"
