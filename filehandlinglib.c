#include <stdlib.h>
#include <stdio.h>

int idGenerator()
{
    FILE *idFile;
    char filename[] = "id_value.txt";
    int id = 0;

    idFile = fopen(filename, "r");

    if(idFile==NULL)
    {
        id = 240000;
        idFile = fopen(filename, "w");
        fprintf(idFile,"%d", id);
        fclose(idFile);
    }
    else
    {
        fscanf(idFile, "%d", &id);
        id++;

        idFile = fopen(filename, "w");
        fprintf(idFile,"%d", id);
        fclose(idFile);
    }
    return id;
}