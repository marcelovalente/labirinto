#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Coordenada.h"
#include "Pilha.h"

typedef struct{
    Coordenada vetor[4]; // vetor estatico
    unsigned int    ultimo,
                    primeiro,
                    quantidade;

}Fila;

//extern void enqueue(Fila* fila,ElementoDeFila x); // por referencia
//extern ElementoDeFila dequeue(Fila* fila); // por referencia
extern unsigned int fullQueue(Fila fila); // retornar 0 ou 1
extern unsigned int emptyQueue(Fila fila); // retornar 0 ou 1

#endif // FILA_H_INCLUDED
