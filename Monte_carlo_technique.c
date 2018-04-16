/estimating pi with the use of monte caro technique
#include <stdio.h>
#include<pthread.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>

long int i= 0;
long int thread_wanted = 0;
long int counts  = 0;
//int R;
pthread_mutex_t lock;
 
void * total_points(void * arg);
void * total_points(void * arg)
{
 pthread_mutex_lock(&lock);
 for(i=0;i<thread_wanted;i++)
 {
 //printf("Ranom _max %d ", RAND_MAX);
  double x= (double)rand()/RAND_MAX;
  double y = (double)rand()/RAND_MAX;
//  printf("Cordinate x : %f Cordinate y : %f\n",x,y);
  double z = x*x + y*y;
//pthread_mutex_lock(&lock);
  if(z<=.18 && counts<thread_wanted)
  {
        //printf("Cordinate x : %f Cordinate y : %f\n",x,y);
        counts++;
  }
 }
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
 
int main()
{
 printf("enter the number of points u want to generate");
 scanf("%ld",&thread_wanted);
 pthread_t thread[thread_wanted];
//printf("Enter the value of radius");
//scanf("%d",&R);
srand(time(0));
 for(i=0;i<thread_wanted;i++)
 {
  pthread_create(&thread[i],NULL,total_points,NULL);
 }
for(i=0;i<thread_wanted;i++)
 {
  pthread_join(thread[i],NULL);
 }
 double points = 4.0 * counts;
 double pi = points / thread_wanted;  //thread_wanted == total_number_of_points
 printf("value pf pi is %.2f ",pi);
}
 

 
//function for calculating total numbers of points being generated within circle
 
//return NULL;

