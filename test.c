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

    for (int i = 0; i < len; i++)
    {
        printf("%s\n", strarr[i]);
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

    printf("%s\n", strCsvForm);
    printf("strToCsvFormatTest test end...\n");
}

void idGeneratorTest()
{
    printf("%d\n", idGenerator());
}