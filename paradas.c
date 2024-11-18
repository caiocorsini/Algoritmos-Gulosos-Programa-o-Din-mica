#include <stdio.h>
#include <limits.h>
#define TAM 10


//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o paradas paradas.c && paradas

void paradas(int postos[], int n, int quant){
    int sol[n];
    for(int i=0; i<n; i++) sol[i]=-1;  // Prepara vetor solucao

    int ultimo = 0;
    int j=0;
    for(int i=1; i<n; i++){
        if(postos[i] - ultimo > quant){
            ultimo = postos[i-1];
            sol[j] = i-1;
            j++;
        }
    }

    for(int i=0; i<j; i++) printf("%d ", sol[i]);
}


void main(){
    int postos[TAM] = {10, 30, 32, 60, 100, 140, 144, 160, 170, 200};  // Distancias desde o inicio
    int target = 210;
    int capac = 45;
    paradas(postos,TAM,capac);
}