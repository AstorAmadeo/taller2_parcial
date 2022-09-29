#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
   char c;
   char *cadena;
} char_string;

int cantidad(char_string*);
int* ocurrencias(char_string*);

int main(void)
{
   char_string cs1;
   cs1.c = 'a';
   cs1.cadena = "hola mundo que tal!";

   printf("posicion de memoria cadena %p\n", &cs1.cadena);

   int canti = cantidad(&cs1);
   printf("cantidad apariciones de letra: %d\n\n", canti);

   int* arr = ocurrencias(&cs1);
   printf("\n\n\n%d\n\n\n", *(arr + 1));
   if (arr == NULL) {
      printf("No se pudo reservar memoria");
      return -1;
   }

   printf("posiciones donde aparece\n");
   for (int i = 0; i < canti; i++) {
     printf("%d\n", *(arr + i));
   }

   return 0;
}

int cantidad(char_string* cs) {

  int contador = 0;
  char *cadena = cs->cadena;

  while(*cadena != '\0') {
     if (*cadena == cs->c) {
         contador++;
     }
     cadena++;
  }

  return contador;
}

int* ocurrencias(char_string* cs) {
  int cant = cantidad(cs);
  int* arr = (int*) malloc(sizeof(int) * cant);
  if (arr == NULL) {
     return NULL;
  }

  int contador = 0;
  char *cadena = cs->cadena;
  while (*cadena != '\0') {
    if (*cadena == cs->c) {
      *(arr + contador) = cadena - cs->cadena;
      contador++;
    }
    cadena++;
  }

  return arr;
}

