#! /bin/bash

if [[ -e ./dist ]]; then
    rm -r ./dist
fi

make -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/lfc-analyzer 
if [[ ! -d ./bin ]]; then
    mkdir bin || { echo "Cannot create directory bin"; return -1; }
fi
cd bin || { echo "Directory bin does not exist"; return -1; }
cp ../dist/Release/GNU-Linux-x86/lfc-analyzer ./ || { echo "Cannot copy ../dist/Release/GNU-Linux-x86/lfc-analyzer to bin directory"; return -1; }
cd .. || { echo "Error in changing directory to project directory"; return -1; }
echo "Installation successful"
