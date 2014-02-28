#! /bin/bash

FILES=./log-201*.gz

../../install.sh
for file in $FILES
do
    echo "test " $file
    date="${file:6:8}"
    result_file="result-"$date.txt
    ../bin/lfc-analyzer -ucrt -i $file > $result_file
    if grep -q "Segmentation fault" "$result_file"; then
        echo "File" $result_file "contains seg fault"
        break
    fi
done
