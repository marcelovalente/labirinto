#include "Fila.h"
/*void enqueue (Fila* fila, ElementoDeFila x){

}*/
/*ElementoDeFila dequeue (Fila* fila){

}*/
unsigned int fullQueue (Fila fila){
    if(fila.quantidade == 0)
        return 1;
    return 0;
}
unsigned int emptyQueue (Fila fila){
    if(fila.quantidade == 4)
        return 1;
    return 0;
}
