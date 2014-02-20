#!/usr/bin/bash

./install.sh
./bin/lfc-analyzer -cet -i $1 > ./logs/result-with-messages.txt
DIR=`date +%Y%m%d-%H:%M:%S``basename "$1"`
mkdir ../$DIR
cp logs/result-with-messages.txt ../$DIR
cd ../$DIR
python ../lfc-analyzer/plot-creator.py result-with-messages.txt
