#!/bin/bash
FILES=./log-2014*.gz

for file in $FILES
do
    gunzip $file
    date="${file:6:8}"
    log_file=${file%.*}
    echo $log_file
    echo result-$date.txt
    ../bin/lfc-analyzer -uc -i $log_file > result-$date.txt
    rm $log_file
done
