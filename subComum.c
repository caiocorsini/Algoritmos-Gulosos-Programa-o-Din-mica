#include <stdio.h>
#include <limits.h>
#define TAM 7

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o subComum subComum.c && subComum

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int maiorSub2(int lin, int col, int sol[lin][col], int arr1[], int arr2[]){
    for(int i=1; i<lin; i++){
        for(int j=1; j<col; j++){
            if(arr1[i-1] == arr2[j-1]){  // Ve se as bases batem
                sol[i][j] = sol[i-1][j-1]+1;  // Soma baseado no diagonal esq
            } else {
                if(sol[i-1][j] >= sol[i][j-1]) sol[i][j] = sol[i-1][j];
                else sol[i][j] = sol[i][j-1];
            }
        }
    }
    printMatrix(lin,col,sol);
    return sol[lin-1][col-1];
}

int maiorSub(int arr1[], int n1, int arr2[], int n2){
    int sol[n1+1][n2+1];  // Prepara matriz auxiliar
    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++) sol[i][j] = 0;
    }

    return maiorSub2(n1+1,n2+1,sol,arr1,arr2);
}



void main(){
    int arr1[TAM] = {1,2,3,2,4,1,2};
    int arr2[TAM] = {2,4,3,1,2,2,1};
    printf("%d", maiorSub(arr2,TAM,arr1,TAM));
}