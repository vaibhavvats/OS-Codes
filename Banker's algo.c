#include<stdio.h>

int i,j,max[100][20],all[100][20],need[100][20];
int fin[100],ava[20],work[20],p,r;
int count,cou,flag;
int arr[99999];
int arc=0;

void check()
{
             y:
             for(i=0;i<p;i++)
                  {

                       // printf("d");
                        flag=0;
                        if(fin[i]==0)
                        {
                            count=0;
                          //  printf("e");
                                    for(j=0;j<r;j++)
                                        {
                                            //printf("f");
                                            if(need[i][j]<=work[j])
                                                    {
                                                      count++;
                            //                          printf("c");
                                                    }
                                        }

                                if(count==r)
                                    {
                              //          printf("b");
                                        //printf("%d process",i);
                                        arr[arc]=i;
                                        arc++;
                                        fin[i]=1;
                                        for(j=0;j<r;j++)
                                        {
                                                work[j]=work[j]+need[i][j];
                                        }

                                         goto y;
                                    }

                            }


                       }



       cou=0;
      for(i=0;i<p;i++)
       {
      //  printf("t");
        if(fin[i]==1)
           cou++;
        }

      //printf("s");
      if(cou!=p)
         printf("Unsafe\n");
       else
         {printf("safe Seuence\n");
          for(i=0;i<arc;i++)
            printf("%d\t",arr[i]);
         }
}


int main()
{
printf("Enter number of resources :\n");
scanf("%d",&r);

printf("Enter number of processes :\n");
scanf("%d",&p);

printf("Enter maximum matrix :\n");
for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      scanf("%d",&max[i][j]);

printf("Enter allocation matrix :\n");
for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      scanf("%d",&all[i][j]);


  for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
          {
              need[i][j]=max[i][j]-all[i][j];
          }
    }

  for(i=0;i<p;i++)
    fin[i]=0;

  printf("Enter details of available resources:\n");
     for(j=0;j<r;j++)
       {
        scanf("%d",&ava[j]);
         work[j]=ava[j];
        }


  check();


}
