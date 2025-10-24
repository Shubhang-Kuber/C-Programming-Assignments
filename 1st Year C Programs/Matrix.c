#include<stdio.h>
#include<stdlib.h>

int main(){
    int row, col, diagonalSum=0, matrixSum=0;
    printf("Enter the Row of the matrix\n");
    scanf("%i", &row);
    printf("Enter the column of the matrix\n");
    scanf("%i", &col);

    int arr[row][col];

    printf("Enter the elements of the matix\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%i", &arr[i][j]);
        }
    }

    for(int i=0; i<row; i++){
        
            diagonalSum=diagonalSum+arr[i][i];
        
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrixSum=matrixSum + arr[i][j];
        }
    }

    printf("The Diagonal SUm is %i", diagonalSum);
    printf("The Diagonal SUm is %i", matrixSum);

    

}