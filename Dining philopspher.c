#include<stdio.h>

int chopstick[5]={1,1,1,1,1};
int state[5]={0,0,0,0,0};

void wait(int *p)
{
while(*p<=0);
*p = *p-1;
}

void fun()
{
int i;
for(i=0;i<5;i++)
 {
 if(state[i]==0)
   printf("Philospher %d is thinking.\n",i);
 else if(state[i]==1)
   printf("Philospher %d is hungry.\n",i);
 else if(state[i]==2)
   printf("Philospher %d is eating.\n",i);

 }

}

void signal(int *p)
{
*p = *p+1;
}

int main()
{
int n,i,p;
int hu[5];

printf("\nEnter how many are hungry?");
scanf("%d",&n);

printf("\nEnter who are hungry?");
for(i=0;i<n;i++)
 {
  scanf("%d",&hu[i]);
  state[hu[i]]=1;
  }

for(p=0;p<n;p++)
{
i=hu[p];

while(state[(i+1)%5]==2 || state[(i+4)%5]==2);
wait(&chopstick[i]);
wait(&chopstick[(i+1)%5]);
state[i]=2;
fun();
printf("\n");
state[i]=0;
signal(&chopstick[i]);
signal(&chopstick[(i+1)%5]);

}


}
