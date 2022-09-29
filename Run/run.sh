#!/bin/sh

#gcc bubbleSortAverage.c -o cOutput/bubbleSort
gcc quickSortAverage.c -o cOutput/quickSort
gcc countingSortAverage.c -o cOutput/countingSort

cd cOutput

#./bubbleSort >> ../csvOutput/bubbleSort.csv
./quickSort >> ../csvOutput/quickSort.csv
./countingSort >> ../csvOutput/countingSort.csv

