#include <stdlib.h>
#include <stdio.h>
#include "strflib.h"
#include "filehandlinglib.h"

void strSplitTest()
{
    printf("strSplitTest test start...\n");
    char str[] = "Hello,world,malunggay,at,tinapay";
    char strarr[STR_MAX_LEN][FILE_LINE];
    char delimiter[] = ",";
    int len = strSplit(str, strarr, delimiter);
    printf("test string: %s", str);

    for (int i = 0; i < len; i++)
    {
        printf("output: %s\n", strarr[i]);
    }
    printf("strSplitTest test end...\n\n");
}

void strToCsvFormatTest()
{
    printf("strToCsvFormatTest test start...\n");

    char strarr[STR_MAX_LEN][STR_MAX_LEN] = {"Mark", "Lanuzo", "BSIT-1.7", "DEv"};
    char delimiter[] = ",";
    char strCsvForm[STR_MIN_LEN];

    strToCsvFormat(strarr, delimiter, strCsvForm, 4);

    printf("output: %s\n", strCsvForm);
    printf("strToCsvFormatTest test end...\n\n");
}

void idGeneratorTest()
{
    printf("%d\n", idGenerator());
}

void saveUserTest()
{
    printf("saveUserTest test start...\n");

    char *userDetailsCsvFormDummy = "240000,mj,mark,lanuzo,2-24-2000,BSIT-1.7,{90,90,91,91,89,89}";
    saveUser(userDetailsCsvFormDummy, 0);
    printf("saveUserTest test end...\n");
}