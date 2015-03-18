#include<stdio.h>

int find(int st[],int p,int fi)
 {
     int i;
     for(i=0;i<p;i++)
     {
         if(st[i]==fi)
            return 1;
     }

     return 0;
 }

int main()
{

    int st[20];
    int arr[100],n,p,i,nopf,pos,j;
    float hr;


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


    for(i=0;i<n;i++)
    {
        if(find(st,p,arr[i])==1)
            continue;
        else
          {
                  pos=(pos+1)%p;
                  st[pos]=arr[i];
                  nopf++;
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
