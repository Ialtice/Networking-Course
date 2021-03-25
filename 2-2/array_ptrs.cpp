#include <iostream>
#include <string>
using namespace std;

int main()
{
    //a.
    int my_ints[4];
    
    //b.
    cout << "Enter four numbers" << endl;
    for(int i = 0; i < 4; i++)// gets 4 numbers from user and puts them into my_ints array
    {
        cout << "Enter a number : ";
        cin >> my_ints[i];
    }
    
    //c.
    int *my_ptrs[4];
    for(int i = 0; i < 4; i++)//intialize all pointers in my_ptrs to the corresponding initial state values in array my_ints
    {
        my_ptrs[i] = &my_ints[i];
    }
    
   //d.
    int i,key,index;
    for(i = 1; i<4; i++)//loop to select each number in array for comparison
    {
        key = *my_ptrs[i];//key holds current value to be compared 
        index = i;// holds current position in my_ptrs array
        while(index > 0 && *my_ptrs[index-1] > key)// loop until end of array is reached or a value smaller than current value
        {
            my_ptrs[index] = my_ptrs[index - 1];//shift all memory location to the right
            index = index -1;
        }
        my_ptrs[index] = &my_ints[i];//puts correct memory location from my_ints with correct pointer in my_ptrs
                                    //1st pointer = lowest value
    }
    
    //e.
    for(int i = 0; i<4;i++)
    {
        cout << "Value pointed to by my_ptrs[" << i << "]: " << *my_ptrs[i] << endl;//display what value each pointer points to, values should be in increasing order
    }
    
    return 0;
}