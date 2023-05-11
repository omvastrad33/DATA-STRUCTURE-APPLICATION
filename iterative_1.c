#include<stdio.h>
int digits(int n);
int main()
{
    int n,d;
    int c=0;
    printf("enter the number:");
    scanf("%d",&n);
    d=digits(n);
    printf("%d",d);
    return 0;
}
int digits(int n)
{

    int c=0;
    while(n)   //A while loop is an pre test loop which tests the specified conditional condition  and as long the condition is true the body is executed. It is also known as entry controlled loop//
    {
        n=n/10;
        c++;
    }
    return c;
}
