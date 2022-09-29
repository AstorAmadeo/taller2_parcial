#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arreglo[10] = "tarola";

    printf("%s\n", arreglo);

    printf("----------------------------\n\n");

    char arreglo_aux[1] = arreglo + 5;
    printf("%s\n\n", arreglo_aux);

    return 0;
}
