#include "revert_string.h"

void RevertString(char *str)
{
    int length = strlen(str);
    int i = 0, j = length - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }		
}

