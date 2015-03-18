#include<stdio.h>

int i,n,j,k,p,m;
int choosing[20]={0};
int number[20]={0};
int a[20];

int max()
{
int posd=0;
for(k=0;k<20;k++)
{
    if(number[k]>number[posd])
        posd=k;
}

    return number[posd];
}

int fun(int a,int b,int c,int d)
{
    if(a<c)
        return 1;
    else if(a==c && b<d)
         return 1;
    else
        return 0;
}

int main()
{


printf("Enter how many users\n");
scanf("%d",&n);

printf("Enter users");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);

for(i=0;i<n;i++)
 {
     p=a[i];
     choosing[p]=1;
     number[p]=max()+1;
     choosing[p]=0;
     for(j=0;j<20;j++)
     {
         //printf("J %d\n",j);
         while(choosing[j]==1);
         while(number[j]!=0 && fun(number[j],j,number[p],p)==1);
     }

     for(k=0;k<10;k++)
     printf("%d is in critical section\n",p);

     number[p]=0;

 }

}
