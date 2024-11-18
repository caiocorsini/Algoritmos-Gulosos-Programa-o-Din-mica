#include <stdio.h>
#include <limits.h>
#define TAM 8

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o multMatriz multMatriz.c && multMatriz

int MatrixChainOrder(int p[], int n){
    int m[n][n];
    int i, j, k, L, q;
 
    for (i = 1; i < n; i++)
        m[i][i] = 0;  // Diagonal de zeros
 
    // L = comprimento de chain. Sao aqueles "Cs" que voce faz em baixo e vao aumentando.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {  // Vai ate o final da chain (subsecao) atual
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];  // Formula
                if (q < m[i][j]) m[i][j] = q;  // Atualiza a matriz com o minimo
            }
        }
    }
    return m[1][n - 1];  // Retorna o top right da matriz de resultados pois o resultado esta la
}
 
// Driver code
void main(){
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, size));
}