#!/bin/sh
echo "Build script pour les TP"
cd TP2
echo "build TP2"
make clean
make
./filtre
