#!/bin/sh

for j in 1 2 3; do
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20; do
	for f in `find $1`; do
		cat $f >>$2
	done
	echo abcdefghij${i}klmnopqrstuv${i}wxyz >>$2
	echo {i}@gmail.com >>$2
done
done
