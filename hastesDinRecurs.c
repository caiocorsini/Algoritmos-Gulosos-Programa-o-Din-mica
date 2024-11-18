#include <stdio.h>
#define TAM 8

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o hastesDinRecurs hastesDinRecurs.c && hastesDinRecurs

int max(int a, int b){
    if(a>b) return a;
    return b;
}

// Uso o proprio n como indice. Vou diminuindo.
int corteHaste2(int haste[], int n, int receitas[]){
    if(n==0) return 0;
    if(receitas[n]>=0) return receitas[n];  // Reutilizo receitas ja calculadas
    int maior = -1;
    for(int i=0; i<n; i++){
        maior = max(maior, haste[i] + corteHaste2(haste, n-i-1, receitas));
    }
    receitas[n] = maior;
    return receitas[n];
}

// Forma top down do corteHaste
int corteHaste(int haste[], int n){
    int receitas[n + 1];
    for(int i=0; i<=n; i++) receitas[i] = -1;
    corteHaste2(haste,n,receitas);
}


void main(){
    int haste[TAM] = {1,5,8,9,10,17,17,20};
    printf("%d", corteHaste(haste,TAM));
}