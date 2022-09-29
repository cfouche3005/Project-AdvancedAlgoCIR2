#!/bin/sh

cd ../Algo/quickSort/

gcc quickSortAverage.c -o ../../cOutput/quickSort/quickSortAverage
#gcc quickSortWorst.c -o ../../cOutput/quickSort/quickSortWorst

cd ../../cOutput/quickSort/

./quickSortAverage >> ../../csvOutput/quickSort/quickSortAverage.csv
#./quickSortWorst >> ../../csvOutput/quickSort/quickSortWorst.csv