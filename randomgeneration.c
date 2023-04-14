#include<stdio.h>

void main()
{
    int i,j;
    int n;

    int temp=0;
    FILE* fp1,*fp2;
     fp1=fopen("om.txt","w");
     fp2=fopen("ec.txt","w");
     time_t t;
     srand((unsigned) time(&t));
     n=6;
    int p=n;
     int ar2[n];




    for(i=0;i<n;i++)
    {
        ar2[i]=rand()%10;
        fprintf(fp1,"%d\n",ar2[i]);

    }


     for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
           if(ar2[j]>ar2[j+1])
           {
              temp=ar2[j];
               ar2[j]=ar2[j+1];
               ar2[j+1]=temp;
           }
        }
    }





    for(i=0;i<p;i++)
    {
         fprintf(fp2,"%d\n",ar2[i]);
    }

    fclose(fp1);
    fclose(fp2);
}
