#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SearchInFile(char *str, char *fname);

int main(int argc, char *argv[])
{

/* Se verifica que la entrada sea  mas de dos */
    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
//Se guarda la cadena de caracteres a buscar
    char *str = argv[1];
//Si mi contador argc es = 2 busca la cadena sin el ingreso de algun archivo  
    if (argc == 2)
    {
        char buffer[500];
        while (fgets(buffer, 500, stdin))
        {
            //Comparo el buffer y me cadena ingresada a buscar  
            if (strstr(buffer, str) != NULL)
            {
                printf("%s", buffer);
            }
        }
    }
//Creo que un ciclo para la busqueda en varios archivos
    for (int i = 2; i < argc; i++)
    {
        SearchInFile(argv[i], str);
    }

    return (0);
}

//metodo para buscar en la palabra en el archivo
void SearchInFile(char *fileName, char *str)
{

//instancio mis variables necesarias, un char para guardar la linea donde esta, los tamaños y la varible archivo
    char *line;
    size_t len = 0;
    ssize_t read;
    FILE *file = fopen(fileName, "r");
   // verifico la apertura del archivo
    if (file == NULL)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    // Creo  un ciclo para leer todas las lineas y encontrar la palabra deseada
    while ((read = getline(&line, &len, file)) != -1)
    {
        //Comparo que la linea donde voy y la palabra se encuentre asi de ser afirmativo imprimo la linea  
        if (strstr(line, str) != NULL)
        {
            printf("%s", line);
        }
    }
    fclose(file);
}