#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
 
 
long int i= 0;
long int thread_wanted = 0;
long int counts  = 0;
pthread_mutex_t lock;
 
void * total_points(void * arg);
void * total_points(void * arg)
{
 pthread_mutex_lock(&lock);
 for(i=0;i<thread_wanted;i++)
 {
  int x=(int)rand()%10;
  int y=(int)rand()%10;
  double X = (double)x/10;
  double Y = (double)y/10;
   printf("%f  %f\n",X,Y);
  if(((X*X)+(Y*Y))<=1)
  {
   counts++;
 
  }
 }
 pthread_mutex_unlock(&lock);
}
 
int main()
{
 printf("enter the number of points u want to generate");
 scanf("%ld",&thread_wanted);
 pthread_t thread[thread_wanted];
  
 for(i=0;i<thread_wanted;i++)
 {
  pthread_create(&thread[i],NULL,&total_points,NULL);
 }
  
 for(i=0;i<thread_wanted;i++)
 {
  pthread_join(thread[i],NULL);
 }
 double points = 4.0 * counts;
 double pi = points / thread_wanted;  //thread_wanted == total_number_of_points
 printf("value pf pi is %f",pi);
}
 
//function for calculating total numbers of points being generated within circle
 
//return NULL;

