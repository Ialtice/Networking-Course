/*
 @file: pthreads_skeleton.cpp
 
 @author:Isaac Altice, ialtice@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates pthreads.
 
 @course: ITSC 3146
*/
#include <pthread.h>
#include <iostream>

using namespace std;


void *PrintHello(void *arg)
{
   int actual_arg = *((int*) arg);
   cout << "Hello World from thread with arg: " << actual_arg << "!\n";
   return 0;
}


int main()
{
   pthread_t id;
   int rc;
   cout << "In main: creating thread \n";

   int t;
   cout << "Enter an integer to be passed into pthread function: ";
   cin >> t;
   rc = pthread_create(&id, NULL, PrintHello, (void*) &t);
   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << std::endl;
      return -1;
   }
   

   pthread_exit(0);
}
