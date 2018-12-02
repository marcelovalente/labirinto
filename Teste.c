#include "Pilha.h"
#include "Coordenada.h"
#include "Mapa.h"
void newStack (int capacidade,Pilha *pilha){
    pilha->vetor = (Coordenada*) malloc(capacidade * sizeof(Coordenada));
    pilha->tamanho = capacidade;
    pilha->topo =  0;
}
void push (Pilha* pilha,Coordenada x){
    pilha->topo++;
    pilha->vetor[pilha->topo] = x;
}
Coordenada pop (Pilha* pilha){
    pilha->topo--;
    return pilha->vetor[pilha->topo];
}
int emptyStack (Pilha *pilha){
    if(pilha->topo == -1)
        return 1;
    return 0;
}
/*void dropStack (Pilha* pilha){
    Pilha* aux = pilha;
    while(aux != NULL){
        free(aux);
        aux = pilha->prox;
    }
    free(pilha);
}*/
