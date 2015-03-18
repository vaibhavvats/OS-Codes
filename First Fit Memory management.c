#include<stdio.h>

int main()
{
int i,j,n,p,arr[100],mem[100],flag[100];

printf("Enter no. of free holes : \n");
scanf("%d",&n);

printf("Enter memory available in each hole: \n");
for(i=0;i<n;i++)
  scanf("%d",&arr[i]);

printf("Enter no. of processes that need memory : \n");
scanf("%d",&p);

printf("Enter memory required by each process: \n");
for(i=0;i<p;i++)
  scanf("%d",&mem[i]);

for(i=0;i<p;i++)
  flag[i]=0;

for(i=0;i<p;i++)
  {
  for(j=0;j<n;j++)
    {
    if(arr[j]>=mem[i])
       {
        arr[j]=arr[j]-mem[i];
        flag[i]=1;
        printf("Process %d allocated hole %d.\n",i+1,j+1);
        break;
        }
    }
   }

  for(i=0;i<p;i++)
    {
    if(flag[i]==0)
      printf("Space not available for process %d\n",i+1);
    }

  printf("Spaces after first-fit allocation available are:\n");
  for(i=0;i<n;i++)
    printf("%d\t",arr[i]);


}
