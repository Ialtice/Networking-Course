/*
 
 @author:Isaac Altice, ialtice@uncc.edu
 
 @description: A program that demonstrates pthreads.
 
 @course: ITSC 3146
*/
#include <pthread.h>
#include <iostream>

using namespace std;
int intArray[10];

void *countNegatives(void *arg)
{
   int count = 0;
   for(int i = 0; i < 10;i++)
   {
       if(intArray[i] < 0)
            count++;
   }
   cout << "Total negative numbers: " << count << endl;
   cout << endl;
   return 0;
}
void *average(void *arg)
{
   int sum = 0;
   for(int i = 0; i < 10;i++)
   {
       sum += intArray[i];

   }
   cout << "Average: " << sum / 10 << endl;
   cout << endl;
   return 0;
}
void *reverse(void *arg)
{
   cout << "The numbers in reverse: " << endl; 
   for(int i = 9; i >= 0;i--)
   {
       cout << intArray[i] << endl;

   }
   cout << endl;
   return 0;
}
int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t thread1,thread2,thread3;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   
   
   cout << "Enter 10 numbers " << endl;
   for(int i = 0;i<10;i++)
   {
       cout << "Enter a number: ";
       cin >> intArray[i];
   }
   cout << endl;
   

   rc = pthread_create(&thread1, NULL, countNegatives, NULL);
   for (int count = 0; count < 100000; count++);
   rc = pthread_create(&thread2, NULL, average, NULL);
   for (int count = 0; count < 100000; count++);
   rc = pthread_create(&thread3, NULL, reverse, NULL);
   
   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
    
}
