#! /bin/bash

make CONG=Release
mkdir bin
cd bin
cp ../dist/Release/GNU-Linux-x86/lfc-analyzer ./
cd ..

echo "Installation successful"
