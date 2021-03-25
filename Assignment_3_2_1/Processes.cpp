


#ifndef Processes_cpp
#define Processes_cpp
#include "Processes.h"


using namespace std;


// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
   pid_t tempID = getpid();
   return tempID;
}


// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
   pid_t id = fork();
   
   // DO NOT CHANGE THIS LINE OF CODE
   process_id = id;
   
   
   if(id == -1)
   {
      return "Error creating process";
     
   }
   else if (id == 0)
   {
      cout << "I am a child process!" << endl;
      return "I am bored of my parent, switching programs now";
      
   }
   else
   {
      cout << "I just became a parent!" << endl;
      wait(NULL);
      return "My child process just terminated!";
   }  
}


// Part 3: Working With External Commands"
void replaceProcess(char * args[])
{
   // Spawn a process to execute the user's command.
   pid_t id = fork();
   
   execvp(args[0],args);
   wait(NULL);
}

#endif /* TestProg_cpp */
