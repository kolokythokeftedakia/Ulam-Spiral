#include "prime.h"
#include <stdio.h>

bool isPrime(int** arr, int r, int c){
  
    int tmp=arr[r][c];
    for(int k=2;k<=tmp/2;k++){
        if(tmp%k==0)
            return false;
        else continue;
    }
    return true;
}

void print(int** arr, int dim){
    printf("\n\033[38;5;0m");
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++)
        if(isPrime(arr, i, j))
            printf("\033[38;5;211m*\033[38;5;0m "); // make foreground pink, print * and restore foreground to black
        else
            printf("  ");
        printf("\n");
    }
    printf("\n");
}