#include<stdio.h>

int i,all[3]={-1,-1,-1},ref[100]={-1,-1,-1},chance[3],n,k,ma[3][8],posd;
int fault=0,j=0,pos,count=0;

void shift(int j,int p)
{
    for(k=0;k<7;k++)
        ma[j][k]=ma[j][k+1];

    ma[j][7]=p;
}

int findmin()
{   int posd=0,min;
    int sum[3]={0,0,0};
    for(j=0;j<3;j++)
    {
        for(k=0;k<7;k++)
            sum[j]=sum[j]+ma[j][k]*pow(2,k);
    }

    min=sum[posd];
    for(j=0;j<3;j++)
    {
        if(sum[j]<sum[posd])
            posd=j;
    }

    return posd;
}

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
   // for(i=0;i<n;i++)
    //{
      //  scanf("%d",&ref[i]);
    //}

    for(i=0;i<n;i++)
       {
      // printf("a\n");
       for(k=0;k<3;k++)
       {
           printf("%d\n",all[k]);
       }
       pos=find(ref[i]);
       if(pos==-1)
         {
         fault++;
         if(count<3)
           {
           all[count]=ref[i];
           for(j=7;j>=0;j--)
              ma[count][j]=0;
           ma[count][7]=1;
           for(j=0;j<count;j++)
             shift(j,0);
           count++;
           }
          else
           {
            posd=findmin();
            all[posd]=ref[i];
            shift(posd,1);
            shift((posd+1)%3,0);
            shift((posd+2)%3,0);
            }
         }
         else
          {
            shift(pos,1);
            shift((pos+1)%3,0);
            shift((pos+2)%3,0);
          }
       }

     printf("fault : %d",fault);

}
