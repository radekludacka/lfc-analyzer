#! /bin/bash

make all
mkdir bin
cd bin
cp ../dist/Release/GNU-Linux-x86/lfc-analyzer ./

echo "Installation successful"
