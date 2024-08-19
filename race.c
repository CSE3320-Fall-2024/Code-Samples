#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_THREADS 10000

static void * simple_thread(void *) ;

int x = 5 ;
int y = 0 ;

int main() 
{
  pthread_t tid[ NUM_THREADS ] ; 
  int count = 0 ;
  srand (time(NULL)) ;

  int i;

  for( i = 0; i <  NUM_THREADS ; i++ )
  {
    pthread_create(&tid[i], 0, &simple_thread, 0) ;
  }

  while ( 1 ) 
  {
    x = 5 ;
    if ( x == 5 ) 
    {
      y = x * 2 ;
      assert( y == 10 ) ; 
    }

    usleep( rand() % 100 ) ;
  }
  return 0 ; 
 }

static void * simple_thread(void * unused)
{
  while ( 1 ) 
  {
    x = 100 ;
    usleep( rand() % 100 ) ;
  }
  return NULL ; 
}
