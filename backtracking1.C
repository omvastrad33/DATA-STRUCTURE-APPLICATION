// print all possible strings that can be made by placing spaces //
#include <stdio.h>
#include <string.h>
int main()
{
    const char* str = "ABCD";
    printPattern(str);
    return 0;
}


void printPatternU(const char str[],char buff[], int i,int j, int n)
{
    if (i == n)
    {
        buff[j] = '\0';
        printf("%s\n", buff);
        return;
    }


    buff[j] = str[i];
    printPatternU(str, buff, i + 1, j + 1, n);


    buff[j] = ' ';
    buff[j + 1] = str[i];

    printPatternU(str, buff, i + 1, j + 2, n);
}


void printPattern(const char* str)
{
    int n = strlen(str);


    char buf[2 * n];


    buf[0] = str[0];

    printPatternU(str, buf, 1, 1, n);
}


