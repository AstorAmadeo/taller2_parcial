#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************
IP: 192.168.146.222
Mask: 255.255.255.0
Tengo que devolver el numero de red:
Red: 192.168.146.0
*****************************************/

typedef struct {
    int ip[4];
    int mask[4];
}astor;

int * redsalida(astor*);

int main(void){
    astor est1;
    est1.ip[0] = 192;
    est1.ip[1] = 168;
    est1.ip[2] = 146;
    est1.ip[3] = 222;
    est1.mask[0] = 255;
    est1.mask[1] = 255;
    est1.mask[2] = 255;
    est1.mask[3] = 0;

    int* redast = redsalida(&est1);
    for(int i = 0; i < 4; i++){
        printf("%d.", redast[i]);
    }

    return 0;
}

int * redsalida(astor *estz){
    int* salida = malloc (4*sizeof(int));

    for(int i = 0; i < 4; i++){
        if(i == 3){
            salida[i] = estz->mask[i];
        }else{
            salida[i] = estz->ip[i];
        }
    }

    return salida;
}
