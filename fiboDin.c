#include <stdio.h>
#include <limits.h>
#define TAM 5

//0, 1, 1, 2, 3, 5
//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o fiboDin fiboDin.c && fiboDin

void fibo(int n){
    int sol[n];
    for(int i=0; i<n; i++) sol[i] = 0;  // Inicializa
    sol[1] = 1;
    for(int i=2; i<n; i++)
        sol[i] = sol[i-1] + sol[i-2];
    for(int i=0; i<n; i++) printf("%d ", sol[i]); 
}

void main(){
    fibo(6);
}