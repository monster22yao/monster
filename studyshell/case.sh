#! /bin/sh

echo "Enter a yes or no"
read BUF

case "$BUF" in

	yes|Y|y|YES|Yes)
		echo "It's a yes.";;
	[nN]?)
		echo "It's a no.";;
	*)
		echo "other case.";;
esac

echo "going to return"
return 0
echo "going to return end"
