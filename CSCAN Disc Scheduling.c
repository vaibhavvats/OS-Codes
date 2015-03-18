
#include<stdio.h>

void quicksort(int x[],int first,int last)
{
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

int main()
{
int n,di[100],dp,i;
int sum=0;
int pos,count,ma;

printf("Enter no. of disk accesses:\n");
scanf("%d",&n);

printf("Enter disk numbers of accesses:\n");

for(i=0;i<n;i++)
  scanf("%d",&di[i]);

printf("Enter current disk pointer location:\n");
scanf("%d",&dp);

printf("Enter maximum disk pointer location:\n");
scanf("%d",&ma);

di[n]=dp;
di[n+1]=0;
di[n+2]=ma;

quicksort(di,0,n+3);

for(i=0;i<=n;i++)
{
    if(di[i]==dp)
      {
          pos=i;
          break;
      }
}

count=0;



for(i=pos+1;i<n+3;i++)
  {
    if(i!=n+2)
    sum=sum+abs(di[i+1]-di[i]);
    count++;
    printf("%d Disk access : %d\n",count,di[i]);

  }



i=0;

sum=sum+ma;


for(i=0;i<pos;i++)
  {
    sum=sum+abs(di[i+1]-di[i]);
    count++;
    printf("%d Disk access : %d\n",count,di[i]);

  }

printf("Number of disk movement : %d\n",sum);
}


