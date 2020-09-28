#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SearchInFile(char *str, char *fname);

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *str = argv[1];
    if (argc == 2)
    {
        char buffer[500];
        while (fgets(buffer, 500, stdin))
        {
            if (strstr(buffer, str) != NULL)
            {
                printf("%s", buffer);
            }
        }
    }

    for (int i = 2; i < argc; i++)
    {
        SearchInFile(argv[i], str);
    }

    return (0);
}

void SearchInFile(char *fileName, char *str)
{

    char *line;
    size_t len = 0;
    ssize_t read;
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    while ((read = getline(&line, &len, file)) != -1)
    {
        if (strstr(line, str) != NULL)
        {
            printf("%s", line);
        }
    }
    fclose(file);
}