#include <string.h>
#include "strflib.h"

int strSplit(char *input, char output[STR_MAX_LEN][FILE_LINE], char *delimiter)
{
    int i = 0;
    char *str = strtok(input, delimiter);
  
    while (str != NULL) {
        strcpy(output[i], str);
        str = strtok(NULL, delimiter);
        i++;
    }

    return i;
}

void strToCsvFormat(char strArr[STR_MIN_LEN][STR_MIN_LEN], char *delimiter, char *strInCsvFormat, int len){
    for(int i = 0; i < len; i++)
    {
        strcat(strInCsvFormat, strArr[i]);
        if(i < len-1)
        {
            strcat(strInCsvFormat, delimiter);  
        }
    }
}

void hello();