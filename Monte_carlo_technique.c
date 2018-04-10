//estimating pi with the use of monte caro technique
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>
#define seed 35791246
 
 //radius is fixed i.e 1
long int i= 0;
long int thread_wanted = 0;
long int counts  = 0;//count is counting the number of points generating within the circle
 
int main(int argc,char* argv)
{
  printf("Enter the number of thread wanted to generate coordinates: \n");
  scanf("%ld",&thread_wanted);
  srand(SEED);
   count=0;
   for ( i=0; i<thread_wanted; i++) { 
      X = (double)rand()/RAND_MAX;
      Y = (double)rand()/RAND_MAX;
      Z = X*X+Y*Y;
      if (Z<=1) {
    	//printf("Coordinates is (%d,%d)\n",X,Y);
	  count++;}
      }
   pi=(double)count/thread_wanted*4;//thread_wanted == total number of points
   printf("# of thread generated= %d , estimate value of pi is %g \n",thread_wanted,pi);
}
 
//function for calculating total numbers of points being generated within circle
 
//return NULL;

