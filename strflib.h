#pragma once

#define STR_MIN_LEN 256
#define STR_MID_LEN 512
#define STR_MAX_LEN 1024

#define FILE_LINE 1024

int strSplit(char *input, char output[STR_MAX_LEN][FILE_LINE], char *delimiter);
void strToCsvFormat(char strArr[STR_MAX_LEN][STR_MAX_LEN], char *delimiter, char *strInCsvFormat, int len);