#! /bin/bash

for MYFILE in $(ls) ; do

	printf "$MYFILE  "

	if [ -d "$MYFILE" ]; then
		echo "its a dir."
	elif [ -f "$MYFILE" ]; then
		echo "its a file."
	else
		echo "other."
	fi

done
