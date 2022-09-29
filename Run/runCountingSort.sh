#!/bin/sh

cd ../Algo/countingSort/

gcc countingSortAverage.c -o ../../cOutput/countingSort/countingSortAverage

cd ../../cOutput/countingSort/

./countingSortAverage >> ../../csvOutput/countingSort/countingSortAverage.csv