#include<stdio.h>

typedef struct data
{
int a,b,c;
}data;



int main()
{
data p[10];
data temp;
int i,n,j;

scanf("%d",&n);

for(i=0;i<n;i++)
    scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);

for(i=0;i<n;i++)
  {
  for(j=i+1;j<n;j++)
    {
    if(p[i].a>p[j].a)
      {
      temp=p[i];
      p[i]=p[i+1];
      p[i+1]=temp;
      }
     else if(p[i].a == p[j].a)
       {
         if(p[i].b>p[j].b)
           {
              temp=p[i];
              p[i]=p[i+1];
              p[i+1]=temp;
           }
       }
    }
  }

  for(i=0;i<n;i++)
    printf("%d %d %d\n",p[i].a,p[i].b,p[i].c);
}
