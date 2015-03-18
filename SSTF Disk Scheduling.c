#include<stdio.h>

typedef struct data
{
    int di,f;
}data;

int main()
{
int n,dp,i;
data d[100];
int diff;
int sum=0,count,pos;

printf("Enter no. of disk accesses:\n");
scanf("%d",&n);

printf("Enter disk numbers of accesses:\n");

for(i=0;i<n;i++)
  {
      scanf("%d",&d[i].di);
      d[i].f=0;
  }

printf("Enter current disk pointer location:\n");
scanf("%d",&dp);

count =0;

/*printf("Disk pointer movement are:\n");
while(count!=n)
{
    diff=99999999;
    for(i=0;i<n;i++)
    {
        if(abs(d[i].di-dp)<diff && d[i].f==0)
        {
            diff=abs(d[i].di-dp);
            pos=i;
        }

    }

     sum=sum+abs(d[pos].di-dp);
     dp=d[pos].di;
     d[pos].f=1;
     count++;
     printf("%d disk access : %d\n",count,dp);
}
*/


printf("Number of disk movement : %d\n",sum);
}
