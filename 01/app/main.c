#include <stdio.h>
#include "strutils.h"

int main(void)
{
    char my_string[] = "app123";
    long long int len_my_string = sizeof(my_string) - 1;

    str_reverse(my_string, len_my_string);

    printf("my_string = %s\n", my_string);

    return 0;
}





