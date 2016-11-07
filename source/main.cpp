/*
Dynamically Allocated Arrays
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "../header/frog.h"

// Include iostream for output during the program.
#include <iostream>
// Use std to avoid writing std:: everywhere.
using namespace std;


// Start of main function
int main() 
{
    // As it turns out, arrays and pointers are very similar, and for good reason.
    {
        int numberArray[5] = { 1, 2, 3 };     // Make an array of 5 elements.

        int * numberPointer = &(numberArray[0]);    // Get a pointer to the first element in the array.

        cout << "Arrays are actually just pointers:" << endl;

        cout << "Print array:                       " << numberArray << endl;   // It turns out, an array is no more than a pointer to the stack.
        cout << "Pointer to first element in array: " << numberPointer << endl; // How can we use this information?

        //      There's only  one key difference.
        // numberArray = { 1, 2, 3 };   // This isn't allowed.
        
        cout << "More Correct: Arrays are CONST pointers." << endl;



        // This means we can use a pointer just like we would us an array, and vice versa:
        cout << "\nIndexing into array:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "numberArray[i]:        " << numberArray[i] << endl;
            cout << "*(numberArray + i):    " << *(numberArray + i) << endl;
            cout << "numberPointer[i]:      " << numberPointer[i] << endl;
            cout << "*(numberPointer + i):  " << *(numberPointer + i) << endl;
            cout << endl;
        }
        
    }
    cout << "Press enter to continue . . ." << endl;
    cin.get();


    // Since array are secretly just pointers, we can create an array on the heap with new.
    {
        int size = 5;

        // Allocate the array like this:
        int * dynamicArray = new int[size]; // Notice how we can create an array with a variable size because it's allocated dynamically.


        for (int i = 0; i < size; i++)
        {
            dynamicArray[i] = i * size;
        }


        cout << "print data from heap array: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << dynamicArray[i] << " ";
        }
        cout << endl;

        // When deleting this kind of array, use delete[] to make sure all of the memory is properly freed.
        delete[] dynamicArray;  // delete[] deallocates every object in the array (calling destructors if there are any)




        // You may wonder how delete[] can possibly know how to delete every element of the array.
        // It has no way of knowing how many elements there are.

        // The answer: Black Magic:
        // new[] silently keeps track of the length of any arrays you allocate and secretly stores that information "somewhere".
        // It just doesn't share that info with the programmer.



    }
    cin.get();




    // Classes and structs can be created in arrays like this too.
    {
        int size = 2;

        // Allocate the array the same as usual:
        Frog * dynamicArray = new Frog[size];   // This calls the default constructor for each object in the array.

        cin.get();

        for (int i = 0; i < size; i++)
        {
            dynamicArray[i].MakeNoise();
        }

        cin.get();

        // delete objects created with new
        delete[] dynamicArray;  // delete[] calls the destructor of each object in the array.

    }
    cin.get();

    return 0;   // End Program.
}