#include<stdio.h>

int i,all[3]={-1,-1,-1},ref[100]={-1,-1,-1},chance[3],n,k;
int fault=0,j=0,pos,count=0;

int find(int a)
 {
 for(k=0;k<3;k++)
   if(all[k]==a)
     return k;

 return -1;
 }

int main()
{
    printf("Enter the no. of pages in reference string: \n");
    scanf("%d",&n);
    printf("Enter %d page numbers:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ref[i]);
    }

    for(i=0;i<n;i++)
       {
       printf("a\n");
       for(k=0;k<3;k++)
       {
           printf("%d : %d\n",all[k],chance[k]);
       }
       pos=find(ref[i]);
       if(pos==-1)
         {
         fault++;
         if(count<3)
           {
           all[count]=ref[i];
           chance[count]=0;
           count++;
           }
          else
           {
           while(chance[j]!=0)
                {
                 ref[j]=0;
                 j=(j+1)%3;
                }
                all[j]=ref[i];
                chance[j]=0;
            }
         }
         else
          chance[pos]=1;
       }

     printf("%d",fault);

}
