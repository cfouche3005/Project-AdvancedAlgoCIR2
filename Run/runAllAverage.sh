#!/bin/sh

cd ../Algo/bubbleSort/

gcc bubbleSortAverage.c -o ../../cOutput/bubbleSort/bubbleSortAverage

cd ../../cOutput/bubbleSort/

./bubbleSortAverage >> ../../csvOutput/allAverage/bubbleSortAverage.csv

cd ../

cd ../Algo/countingSort/

gcc countingSortAverage.c -o ../../cOutput/countingSort/countingSortAverage

cd ../../cOutput/countingSort/

./countingSortAverage >> ../../csvOutput/allAverage/countingSortAverage.csv

cd ../

cd ../Algo/quickSort/

gcc quickSortAverage.c -o ../../cOutput/quickSort/quickSortAverage

cd ../../cOutput/quickSort/

./quickSortAverage >> ../../csvOutput/allAverage/quickSortAverage.csv

