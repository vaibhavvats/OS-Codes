#include<stdio.h>

int main()
{
int i,j,n,p,arr[100],mem[100],flag[100];
int count,small,pos;

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
  count=0;
  small=99999999;
  for(j=0;j<n;j++)
    {

    if(arr[j]>=mem[i] && count==0)
        {
        count++;
        small=arr[j];
        pos=j;
        flag[i]=1;
         }

     if(arr[j]>small && arr[j]>=mem[i])
        {
         small=arr[j];
         pos=j;
         flag[i]=1;
        }
    }

    if(flag[i]==1)
    {
        arr[pos]=arr[pos]-mem[i];
        printf("Process %d alloacted hole %d.\n",i+1,pos+1);
    }
    else
        printf("Space not available for process %d\n",i+1);
   }



  printf("Spaces after worst-fit allocation available are:\n");
  for(i=0;i<n;i++)
    printf("%d\t",arr[i]);


}
