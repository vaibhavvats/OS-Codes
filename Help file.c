#include<stdio.h>

typedef struct data
{
int a;
}data;

int main()
{
FILE *fp;
data p;
p.a=1;

fp=fopen("cha.dat","w+");

 if(fp==NULL)
  {
  puts("Cant open file\n");
  exit(1);
  }
else
    printf("Hello");

fwrite(&p,sizeof(p),1,fp);


fclose(fp);
}
