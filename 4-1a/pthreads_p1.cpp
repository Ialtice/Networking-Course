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
const char* my_messages[4] = {"English: Hello!", "French: Bonjour!", "Spanish: Hola!", "German: Guten Tag!" };

void *printMessage(void *(index))
{
   int i = *((int*)index);
   cout << my_messages[i] << endl;
   return 0;
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   


   
   // Create thread(s)
   for(int i = 0;i < my_messages.size();i++)
   {
      rc = pthread_create(&id, NULL, printMessage, (void*)&i);
      pthread_join(id,NULL);
      if (rc){
         cout << "ERROR; return code from pthread_create() is " << rc << endl;
         return -1;
      }
      
   }
   
   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
