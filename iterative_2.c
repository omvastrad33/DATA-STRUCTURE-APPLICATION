#include<stdio.h>
int decimal(int n);
int main()
{
    int n,d;
    int r;
    int i=1;
    int sum=0;
    printf("enter the binary number:");
    scanf("%d",&n);
    d=decimal(n);
    printf("%d",d);
    return 0;
}
int decimal(int n)
{
    int r;
    int sum;
    int i=1;

    while(n!=0)
    {
        r=n%10;
        sum=sum+r*i;
        n=n/10;
        i=i*2;
    }
    return sum;
}
