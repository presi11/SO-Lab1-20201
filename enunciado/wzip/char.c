#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * eltexto(); //Prototipo: la función devuelve un puntero a un char

int main () 
{
    char* a = eltexto(); //Declaracion de una variable tipo apuntador
    printf("\nEl valor de la funcion 5 es: %s\n",a);       
}

// Declaración de la función
char  *eltexto ()
{
    char *name = "Enrique";
    return name;
}