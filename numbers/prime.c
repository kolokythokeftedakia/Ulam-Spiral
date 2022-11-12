#include "prime.h"
#include <stdio.h>
#include <math.h>

bool isPrime(int** arr, int r, int c){
  
    int tmp=arr[r][c];
    if(tmp==1) return false;
    for(int k=2;k<=(int) sqrt(tmp);k++){
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
            printf("\033[38;5;211m%d\033[38;5;0m\t",arr[i][j]);            
        else
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
