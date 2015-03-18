#include<stdio.h>

typedef struct val
{
int mut,read,wrt;
}val;

typedef struct data
{
int a;
}data;



void wait(int *p)
{
    while(*p<=0);
    *p=*p-1;
}

void signal(int *p)
{
    *p=*p+1;
}

int main()
{
FILE *fe;
FILE *fp;
data p;
val m;
int i;

fp=fopen("cha.dat","r+");
fe=fopen("value.dat","r+");

if(fp==NULL)
  {
  puts("Cant open file\n");
  exit(1);
  }

if(fe==NULL)
  {
  puts("Cant open file\n");
  exit(1);
  }

fread(&p,sizeof(p),1,fp);
if(p.a==0)
  {
   printf("Cant read");
   exit(1);
   }

fread(&m,sizeof(m),1,fe);
wait(&m.mut);
fwrite(&m,sizeof(m),1,fe);
if(m.read==1)
   wait(&m.wrt);
fwrite(&m,sizeof(m),1,fe);
m.read++;
fwrite(&m,sizeof(m),1,fe);
signal(&m.mut);
fwrite(&m,sizeof(m),1,fe);

for(i=0;i<100000;i++)
    printf("Reading\n");

wait(&m.mut);
fwrite(&m,sizeof(m),1,fe);
m.read--;
fwrite(&m,sizeof(m),1,fe);
if(m.read==0)
   signal(&m.wrt);
fwrite(&m,sizeof(m),1,fe);
signal(&m.mut);
fwrite(&m,sizeof(m),1,fe);


fclose(fp);
fclose(fe);
}
