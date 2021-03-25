#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};


//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE
int compareToAge(const void * patient1,const void * patient2)
{
    
    if(*(int*)patient1 < *(int*)patient2)
        return -1;
    else if(*(int*)patient1 == *(int*)patient2)
        return 0;
    else
        return 1;
        
}
//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE



//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE
int compareToBalance(const void * patient1,const void * patient2)
{
    
    if(*(float*)patient1 > *(float*)patient2)
        return -1;
    else if(*(float*)patient1 == *(float*)patient2)
        return 0;
    else
        return 1;
        
}
//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE


//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY Name
int compareToName(const void *patient1,const void *patient2)
{
    struct patient *ipatient1 = (struct patient *)patient1;
    struct patient *ipatient2 = (struct patient *)patient2;
    return strncmp(ipatient1 -> name, ipatient2 -> name,20);
}
//
//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)

void DisplayPatients(patient patientList[])
{
    for(int i = 0;i < 5;i++)
    {
        cout << "Age: " << patientList[i].age << "      Name: " << patientList[i].name << "     Balance: $" << patientList[i].balance << endl;
    }
    
    cout << endl;
}

//  The main program
int main()
{
    
    int total_patients = 5;
    
    
    //  Storing some test data
    struct patient patient_list[5] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Maria O'Donell", 375},
        {53, "Pablo Picasso ", 615}
    };
    
    size_t patientsSize = sizeof(patient_list)/sizeof(patient);
    cout << "Patient List: " << endl;
    
    //  TODO:
    //  IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
    //  OF THE ARRAY BEFORE SORTING
   DisplayPatients(patient_list);
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
    qsort (patient_list, patientsSize,sizeof(patient),compareToAge);
    
    cout << "Patient List - Sorted by Age: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY AGE
    
    DisplayPatients(patient_list);
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    
    cout << "Patient List - Sorted by Balance Due: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY BALANCE
    qsort (patient_list, patientsSize,sizeof(patient),compareToBalance);
    DisplayPatients(patient_list);
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    qsort (patient_list, patientsSize,sizeof(patient),compareToName);
    cout << "Patient List - Sorted by Name: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY NAME
    DisplayPatients(patient_list);
    cout << endl;
    
    return 0;
}
