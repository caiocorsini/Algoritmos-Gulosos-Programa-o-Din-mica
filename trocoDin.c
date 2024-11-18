#include <stdio.h>
#include <limits.h>
#define TAM 7

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o trocoDin trocoDin.c && trocoDin

int min(int a, int b){
    if(a<b) return a;
    return b;
}

int troco(int moedas[], int n, int valor){
    int sol[valor+1];
    for(int i=0; i<valor+1; i++) sol[i] = INT_MAX;
    sol[0] = 0;

    for(int i=0; i<valor+1; i++)
        for(int j=0; j<n; j++)
            if(i >= moedas[j])
                sol[i] = min(sol[i], sol[i-moedas[j]]+1);
    
    return sol[valor];
}


void main(){
    int moedas[TAM] = {1, 2, 5, 10, 20, 50, 100};
    printf("%d", troco(moedas,TAM,70));
}