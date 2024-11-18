#include <stdio.h>
#include <limits.h>
#define TAM 5

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o fatorialDin fatorialDin.c && fatorialDin

int fat(int n){
    int sol[n+1];
    for(int i=0; i<=n; i++) sol[i] = 1;  // Inicializa
    for(int i=1; i<=n; i++)
        sol[i] = sol[i-1]*i;  // Reutiliza o anterior
    return sol[n];
}

void main(){
    printf("%d", fat(6));
}