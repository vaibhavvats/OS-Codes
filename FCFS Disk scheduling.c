#include<stdio.h>

int main()
{
int n,di[100],dp,i;
int sum=0;

printf("Enter no. of disk accesses:\n");
scanf("%d",&n);

printf("Enter disk numbers of accesses:\n");

for(i=0;i<n;i++)
  scanf("%d",&di[i]);

printf("Enter current disk pointer location:\n");
scanf("%d",&dp);

sum=di[0]-dp;

for(i=0;i<n-1;i++)
  sum=sum+abs(di[i+1]-di[i]);

printf("Number of disk movement : %d\n",sum);
}
