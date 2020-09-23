#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void comprimir(char *fname);

int main(int argc, char *argv[]) {

    for(int i=1; i<argc; i++){
        comprimir(argv[i]);
        
    }
    return(0);
 }

void comprimir(char *fname){
    
    FILE *inFile = fopen(fname, "r");
    //FILE *outFile = fopen(fout, "w");
    char src[500];
    char count[50];

    if (inFile == NULL)
    {
        printf("wzip: cannot open file\n");
        exit(1);
    }

    fgets(src, 100, inFile);
    int len = strlen(src);
    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));
 
    int i, j = 0, k;
 
    /* traverse the input string one by one */
    for (i = 0; i < len; i++) {
 
        /* Copy the first occurrence of the new character */
        //dest[j++] = src[i];
 
        /* Count the number of occurrences of the new character */
        int rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }
 
        /* Store rLen in a character array count[] */
        sprintf(count, "%d", rLen);
 
        /* Copy the count[] to destination */
        for (k = 0; *(count + k); k++, j++) {
            dest[j] = count[k];
        }
        dest[j++] = src[i];
    }
 
    /*terminate the destination string */
    dest[j] = '\0';
    printf("%s", dest);
    //int x = strlen(dest);
    //printf("%d", x);
    //fwrite(dest, 2, sizeof(dest) , outFile );
    fclose(inFile);
    //fclose(outFile);
}
