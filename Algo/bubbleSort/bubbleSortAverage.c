#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

//------------AUX----------------------------------------------------------------

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int *array, int size){

    for (int i=0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int Maximum(int *array,int size){
    int max = array[0];
    for (int i=1;i<size;i++){
        if (array[i]>max){
            max = array[i];
        }
    }
    return max;
}

int partition(int *array, int start, int end){      //fonction qui a pour but de comparer les éléments avec le pivot et de faire les swaps
    int piv = array[end]; //on selectionne l'element le plus à droite
    int u = (start-1); //pointeur qui va se mettre sur le premier élément plus grand que le pivot rencontré
    for(int j=start; j<=end-1; j++){  	// parcourt tous les élément tableau et les compares au pivot
        if(array[j] <= piv){
            u++;   //si on repère un élément plus petit que le pivot on le swap avec l'élément pointé par u
            swap(&array[u], &array[j]);
        }
    }
    swap(&array[u+1], &array[end]); //on swap ensuite le pivot avec l'élément pointé par u
    return(u+1);
}

//-------COUNTING SORT----------------------------------------------------------

void countingSort(int *array,int size){
    int max = Maximum(array,size);
    int* countingArray = (int*)malloc((max+1)*sizeof(int));
    int* outputArray = (int*)malloc(size*sizeof(int));

    if (countingArray!=NULL && outputArray!=NULL){
        for (int i=0;i<=max;i++){
            countingArray[i]=0;
        }
        for (int i = 0; i < size; i++) {
            countingArray[array[i]]++;
        }
        for (int i = 1; i <= max; i++) {
            countingArray[i] += countingArray[i-1];
        }
        for (int i = size - 1; i >= 0; i--) {
            outputArray[countingArray[array[i]] - 1] = array[i];
            countingArray[array[i]]--;
        }
        for (int i = 0; i < size; i++) {
            array[i] = outputArray[i];
        }
        free(countingArray);

        free(outputArray);
    }
}
//--------BUBBLE SORT----------------------------

void bubbleSort(int *array, int size){
    int temp;
    bool permut = true;
    while (permut == true){
        permut = false;
        for(int j=0; j<size-1; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                permut=true;
            }
        }
    }
}

//--------QUICK SORT----------------------------

void quickSort(int *array, int start, int end){
    if(start<end) {  //il faut trouver le pivot de sorte à ce que les éléments plus petits que le pivot soient à sa gauche et plus grands à droite
        int p = partition(array, start, end);
        quickSort(array, start, p - 1); // appel récursif à gauche du pivot
        quickSort(array, p + 1, end); //appel récursif à droite du pivot
    }
}




int main(){

    srand (time(NULL));
    int n;
    int* arr;
    int tests = 5;
    double time = 0;
    struct timespec start;
    struct timespec end;

    for(int i=0;i<=50;i++){
        if(i==0){
            n = 100;
        }
        else{
            n = 500*i;
        }
        arr = malloc(n*sizeof(int));

        for(int k=0;k<tests;k++){
            for(int j=0;j<n;j++){
                // THIS GENERATES RANDOM ARRAYS ONLY!!
                arr[j] = rand() % 1000000;
            }

            clock_gettime(CLOCK_MONOTONIC, &start);
            // PUT ALGO HERE !!!!!!
            //countingSort(arr,n);
            //quickSort(arr,0,n);
            bubbleSort(arr,n);
            //------------------------
            clock_gettime(CLOCK_MONOTONIC, &end);
            time += (end.tv_sec - start.tv_sec)  + (double) (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        }
        time = time/tests;
        printf("%d;%f\n",n,1000*time); // in milliseconds
        time = 0;
        //printArray(arr,n);
        free(arr);
    }


    return 0;
}