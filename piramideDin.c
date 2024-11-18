#include <stdio.h>
#include <limits.h>
#define TAM 4

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o piramideDin piramideDin.c && piramideDin

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int somaPiramide(int n, int piramide[n][n]){
    int sol[n][n];  // Piramide de solucoes
    for(int i = n-1; i>=0; i--){  // Comeco pela base da piramide
        for(int j=0; j<=i; j++){  // Checa as colunas
            if(i == n-1) sol[i][j] = piramide[i][j];
            else sol[i][j] = max(sol[i+1][j]+piramide[i][j] , sol[i+1][j+1]+piramide[i][j]);
        }
    }
    return sol[0][0];  // Retorna o topo da piramide de solucoes. Onde esta a soma maxima.
}
 
// Driver code
void main(){
    int piramide[TAM][TAM] = {
        {3,0,0,0},
        {7,4,0,0},
        {2,4,6,0},
        {8,5,9,3}
    };
    printf("\n\n%d", somaPiramide(TAM, piramide));
}