#include <stdio.h>
#include <limits.h>
#define TAM 6


//cls && cd "C:\Users\caiof\Documentos disco local\aaaComputacao_faculdade\analise algoritmos 2\estudo prova" && gcc -o selectAtiv selectAtiv.c && selectAtiv

void selecionar(int start[], int finish[], int n){
    int sol[n];
    for(int i=0; i<n; i++) sol[i]=-1;  // Prepara vetor solucao
    sol[0] = 0;

    int i = 1;
    int j = 0;
    while(i<n){
        if(start[i] > finish[j]){
            j++;
            sol[j] = i;
        }
        i++;
    }
    
    for(int i=0; i<=j; i++) printf("%d ", sol[i]);  // Printa solucao
}


void main(){
    int start[TAM]  = {1, 3, 0, 5, 8, 5};
    int finish[TAM] = {2, 4, 6, 7, 9, 9};
    selecionar(start,finish,TAM);
}