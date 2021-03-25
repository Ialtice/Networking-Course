#include <iostream>
#include <string>
using namespace std;

int main()
{
    //a.
    int myInt = 15;
    int *myPointer = &myInt;
    //b.
    cout << "Memory location of myInt: " << &myInt << endl;
    cout << "Value of myPointer: " << myPointer << endl;
    cout << "Value of myInt: " << myInt << endl;
    cout << "Value pointed to by myPoint: " << *myPointer << endl;
    cout << endl;
    //c
    myInt = 10;
    cout << "Memory location of myInt: " << &myInt << endl;
    cout << "Value of myPointer: " << myPointer << endl;
    cout << "Value of myInt: " << myInt << endl;
    cout << "Value pointed to by myPoint: " << *myPointer << endl;
    
    return 0;
}