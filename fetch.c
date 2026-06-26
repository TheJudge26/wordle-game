#include <stdio.h>
#include "fetch.h"

void readfile(char *filename,char *buffer){

    FILE *file=fopen(filename,"r");

    if (file == NULL) {
        printf("Error: Could not find the file '%s'!\n", filename);
        return; 
    }

    fgets(buffer, 10, file);

    fclose(file);


}