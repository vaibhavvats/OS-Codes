//#include <pthread.h>
//#include<semaphore.h>
#include<sys/time.h>    /* timeval{} for select() */
#include<stdio.h>
#include<stdlib.h>

#define NBUFF            10
#define MAXNTHREADS     100

int nitems, nproducers, nconsumers;

struct
{  int buff[NBUFF];
  int nput;
  int nputval;
  sem_t mutex, nempty, nstored; /* semaphores, not pointers */
}
shared;

void *produce (void *), *consume (void *);

int
main (int argc, char **argv)
{
  int i,ccount[MAXNTHREADS], pcount[MAXNTHREADS];
  pthread_t tid_consume[MAXNTHREADS],tid_produce[MAXNTHREADS] ;

  if (argc != 4)
    {
      printf ("Invalid no. of arguments. Need nitems and nproducers. \n");
      exit (3);
    };

  nitems = atoi (argv[1]);

  nproducers = min (atoi (argv[2]), MAXNTHREADS);
  nconsumers = min (atoi(argv[3]), MAXNTHREADS);
  /* initialize three semaphores */
  sem_init (&shared.mutex, 0, 1);
  sem_init (&shared.nempty, 0, NBUFF);
  sem_init (&shared.nstored, 0, 0);
  for (i = 0; i < nproducers; i++)
    {
      pcount[i] = 0;
      pthread_create (&tid_produce[i], NULL, produce, &pcount[i]);
    }
  for (i = 0; i < nconsumers; i++)
    {
      ccount[i] = 0;
      pthread_create (&tid_consume[i], NULL, consume, &ccount[i]);
    }

   for (i = 0; i < nproducers; i++)
      pthread_join (tid_produce[i], NULL);
  for (i = 0; i < nconsumers; i++)
      pthread_join (tid_consume[i], NULL);

  printf ("\n Number of buffer items contributed by each thread: \n");
  for (i = 0; i < nproducers; i++)
      printf ("pcount[%d] = %d\n", i, pcount[i]);
      for (i = 0; i < nconsumers; i++)
      printf ("ccount[%d] = %d\n", i, ccount[i]);
   sem_destroy (&shared.mutex);
  sem_destroy (&shared.nempty);
  sem_destroy (&shared.nstored);
  exit (0);
}

/* include produce */
void *produce (void *arg)
{
  for (;;)
    {
      sem_wait (&shared.nempty);        /* wait for at least 1 empty slot */
      sem_wait (&shared.mutex);

      if (shared.nput >= nitems)
        {
          sem_post (&shared.nempty);
          sem_post (&shared.mutex);
          return (NULL);
        }
      shared.buff[shared.nput % NBUFF] = shared.nputval;
      printf ("p:%d ", shared.nputval);
      shared.nput++;
      shared.nputval++;
      sem_post (&shared.mutex);
      sem_post (&shared.nstored);
  *((int *) arg) += 1;      }
}
/* end produce */

/* include consume */
void *consume (void *arg)
{
  int i;

  for (i = 0; i < nitems; i++)
     //for(;;)
    {
      sem_wait (&shared.nstored);
      sem_wait (&shared.mutex);
      if (shared.buff[i % NBUFF] != i)
        printf ("error: buff[%d] = %d\n", i, shared.buff[i % NBUFF]);
      printf ("c:%d ", shared.buff[i % NBUFF]);
      sem_post (&shared.mutex);
      sem_post (&shared.nempty);           }
  return (NULL);
}
/* end consume */
int
min (int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}
