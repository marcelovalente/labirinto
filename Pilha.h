#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "Coordenada.h"

typedef struct{
    Coordenada* vetor; // vetor dinamico
     int topo, tamanho;
}Pilha;

extern void newStack (int capacidade,Pilha *pilha); // malloc
extern void push (Pilha* pilha,Coordenada x); // por referencia
extern Coordenada pop (Pilha* pilha); // por referencia
extern int emptyStack (Pilha *pilha); // retornar 0 ou 1
//extern void dropStack (Pilha* pilha); // free

#endif // PILHA_H_INCLUDED
