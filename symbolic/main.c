#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

int main(void){

    printf("\033[48:5:0m\033[2J\033[1;1H"); //set foreground to black, erase the entire console and place cursor @(1,1)
    int dim;
    printf("Dimensions:");
    scanf("%d",&dim);
    int** arr=malloc(sizeof(int*)*dim);
    for(int i=0;i<dim;i++)
        arr[i]=malloc(sizeof(int)*dim);
    
    int pop=dim*dim;   

    int starting_row=(dim/2.0)+1-1;
    int starting_col=ceil(dim/2.0)-1-1;

    int dx=0;
    int dy=0;
    int lnum=2;
    int prev=0;
    int moves[4]={lnum, lnum, lnum-1, lnum}; // l r u d
    enum directions {left, right, up, down};
    enum directions dir=right;
    int cnt=0;

    while(cnt<pop){
        switch(dir){
            case left:
                dx=-1;
                dy=0;
                break;
            case right:
                dx=1;
                dy=0;
                break;
            case up:
                dx=0;
                dy=-1;
                break;
            case down:
                dx=0;
                dy=1;
                break;
        }
        if(moves[dir]>0){
            arr[starting_row+dy][starting_col+dx]=prev+1;
            ++cnt;
            prev=arr[starting_row+dy][starting_col+dx];
            starting_col+=dx;
            starting_row+=dy;
            --moves[dir];
        }else{
            switch(dir){
                case right:
                    dir=up;
                    break;
                case up:
                    dir=left;
                    break;
                case left:
                    dir=down;
                    break;
                case down:
                    dir=right;
                    lnum+=2;
                    moves[right]=lnum-1;
                    moves[up]=lnum-1;
                    moves[left]=lnum;
                    moves[down]=lnum;
            }
        }
    }

    print(arr,dim);
    

    for(int i=0;i<dim;i++){
        free(arr[i]);
        arr[i]=NULL;
    }

    free(arr);
    arr=NULL;

    return 0;
}