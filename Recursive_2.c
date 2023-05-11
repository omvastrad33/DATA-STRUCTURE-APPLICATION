#include <stdio.h>
void EvenAndOdd(int a, int n);

int main()
{
    int n;
        printf(" Input the range to print starting from 1 : ");
    scanf("%d", &n);

    printf("All even numbers from 1 to %d are : ", n);
    EvenAndOdd(2, n);

    printf("\n\n All odd numbers from 1 to %d are : ", n);
    EvenAndOdd(1, n);

    printf("\n\n");

    return 0;
}
void EvenAndOdd(int a, int n)
{
    if(a > n)
        return;
    printf("%d  ", a);
    EvenAndOdd(a+2, n);
}
