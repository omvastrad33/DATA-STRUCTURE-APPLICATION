          //MULTIPLICATION TABLE OF A GIVEN NUMBER//
#include<stdio.h>
int main()
 {

    int i, n, r;
    printf("Enter a number: ");
    scanf("%d", & n);
    printf("Enter the range: ");
    scanf("%d", & r);
    printf("Multiplication table of %d:\n", n);
    multiplication_table(n, r);
 return 0;
}
void multiplication_table(int n, int r)
 {

    if (r == 0)
        return;

    multiplication_table(n, r - 1);

    printf("%d x %d = %d\n", n, r, n * r);
}

