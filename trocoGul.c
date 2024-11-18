#include <stdio.h>
#include <limits.h>
#define TAM 3

//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o trocoGul trocoGul.c && trocoGul

void troco(int moedas[], int n, int quant){
    int sol[n];
    for(int i=0; i<n; i++) sol[i] = 0;

    int i=0;
    while(quant > 0){
        if(quant >= moedas[i]){
            sol[i]++;
            quant -= moedas[i];
        } else {
            i++;
        }
    }

    for(int i=0; i<n; i++) printf("%d ", sol[i]);
}


void main(){
    int moedas[TAM] = {5,2,1};
    int quant = 12;
    troco(moedas,TAM,quant);
}