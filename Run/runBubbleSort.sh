#!/bin/sh

cd ../Algo/bubbleSort/

#gcc bubbleSortAverage.c -o ../../cOutput/bubbleSort/bubbleSortAverage
gcc bubbleSortBest.c -o ../../cOutput/bubbleSort/bubbleSortBest
#gcc bubbleSortWorst.c -o ../../cOutput/bubbleSort/bubbleSortWorst

cd ../../cOutput/bubbleSort/

#./bubbleSortAverage >> ../../csvOutput/bubbleSort/bubbleSortAverage.csv
./bubbleSortBest >> ../../csvOutput/bubbleSort/bubbleSortBest.csv
#./bubbleSortWorst >> ../../csvOutput/bubbleSort/bubbleSortWorst.csv

