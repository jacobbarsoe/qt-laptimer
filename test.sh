#!/bin/bash
if [ ! -e test.dat ]; then 
	mkfifo test.dat
fi
while true 
do 
	cat testdata | while read line
	do 
		echo $line > test.dat
		sleep .5
	done
done
