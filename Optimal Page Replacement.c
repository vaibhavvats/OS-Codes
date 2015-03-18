#include<stdio.h>

int fi(int st[],int p,int fin)
 {
     int i;
     for(i=0;i<p;i++)
     {
         if(st[i]==fin)
            return 1;
     }

     return 0;
 }

int fin(int arr[],int j,int n,int fi)
 {
     int i;
     for(i=j;i<n;i++)
     {
         if(arr[i]==fi)
            return i;
     }

     return -1;
 }

int main()
{

    int st[20],m,flag;
    int arr[100],n,p,i,nopf,pos,j,k,count,pi,minpos,minfin;
    float hr;
    int find[20];


    printf("Enter the no. of pages in reference string: \n");
    scanf("%d",&n);
    printf("Enter %d page numbers:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the no. of pages allocated to process: \n");
    scanf("%d",&p);

    pos=0;

    for(i=0;i<p;i++)
         st[i]=-1;

    nopf=0;
    count=-1;

    for(i=0;i<n;i++)
    {
        if(fi(st,p,arr[i])==1)
            continue;
        else
          {
           count++;
           nopf++;
          // printf("%d\n",i);
           if(count<p)
            st[count]=arr[i];
           else
           {
           minpos=-1;
           flag=0;

           for(j=0;j<p;j++)
           {
               pos=fin(arr,i+1,n,st[j]);
               if(pos==-1)
               {
                   minfin=j;
                   flag=1;
               }

               if(pos>minpos && flag==0)
               {
                   minpos=pos;
                   minfin=j;
               }
           }
           st[minfin]=arr[i];
           }
          }

      printf("Pages in frame are :\n");
        for(j=0;j<p;j++)
            if(st[j]!=-1)
               printf("%d  ",st[j]);

      printf("\n");

    }

    hr=(float)(n-nopf)/n;
    printf("No. of page faults: %d\n",nopf);
    printf("Hit ratio: %f",hr);
}
