#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Llamanos el metodo
void leerArchivo(char *nombre);
//Creamos la variable para trabajar con el archivo
FILE *inFile;

int main(int argc, char *argv[])
{ 
  if (argc < 2)
    {
        exit(0);
    }
  
//Iteramos para utilizar el wcat en mas de un archivo
  for(int i=1; i<argc; i++){
    leerArchivo(argv[i]);
  }
  return 0;
}

void leerArchivo(char *nombre){
//Asignamos el archivo entrado por consola en modo "Read" lectura
inFile = fopen(nombre,"r");
char data[50] ;
//Verificamos que se entre un archivo valido
if(inFile == NULL) {
  printf("wcat: cannot open file\n");
  exit(1);
}

//Iteramos para imprirmir todas las lineas del archivo
while( fgets ( data, 50, inFile ) != NULL ){
      printf( "%s" , data ) ;

  }

//Cerramos el archivo
fclose(inFile); 

}