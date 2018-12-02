/*#include "Pilha.h"
#include "Coordenada.h"
#include "Mapa.h"
void newStack (unsigned int capacidade,Pilha *pilha){
    pilha->vetor = (Pilha*) malloc(capacidade * sizeof(Pilha));
    pilha->tamanho = capacidade;
    pilha->topo =  -1;
}
void push (Pilha* pilha,Coordenada x){
    pilha->vetor[pilha->++topo] = x;
}
Coordenada pop (Pilha* pilha){
    return pilha->vetor[pilha->--topo];
}
unsigned int emptyStack (Pilha *pilha){
    if(pilha.topo == -1)
        return 1;
    return 0;
}
void dropStack (Pilha* pilha){
    Pilha* aux = pilha;
    while(aux != NULL){
        free(aux);
        aux = pilha->prox;
    }
    free(pilha);
}*/
