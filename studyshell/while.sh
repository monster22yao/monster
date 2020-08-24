#! /bin/bash

echo "Input a passwd"
read psd

while [ "$psd" != "itcast" ]; do
	printf "Enter again\n"
	read psd
done
