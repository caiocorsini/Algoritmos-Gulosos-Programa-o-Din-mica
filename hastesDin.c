#include <stdio.h>
#define TAM 8

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o hastesDin hastesDin.c && hastesDin

int max(int a, int b){
    if(a>b) return a;
    return b;
}

// Forma bottom up do corteHaste
int corteHaste(int haste[], int n){
    int receitas[n + 1];
    receitas[0] = 0;
    for(int i=1; i<=n; i++) receitas[i] = -1;

    for(int i=1; i<=n; i++){
        int maior = -1;
        for(int j=1; j<=i; j++){
            maior = max(maior, haste[j-1] + receitas[i-j]);
        }
        receitas[i] = maior;
    }
    
    return receitas[n];
}


void main(){
    int haste[TAM] = {1,5,8,9,10,17,17,20};
    printf("%d", corteHaste(haste,TAM));
}