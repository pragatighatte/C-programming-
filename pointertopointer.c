/* 
    POINTER TO POINTER,

   - A pointer is a variable that stores the ADDRESS of another variable.
   - A pointer to a pointer stores the ADDRESS of another POINTER.

   Example idea:
        x  = a house
        p  = a paper with the address of the house
        q  = a paper with the address of the paper 'p'
        r  = a paper with the address of the paper 'q'

   So:
        int* p   → pointer to int
        int** q  → pointer to a pointer to int
        int*** r → pointer to a pointer to a pointer to int

   Each extra * means one more level of indirection.
*/

#include <iostream>
using namespace std;

int main() {
    int x = 5;        // A simple integer variable

    int* p = &x;      // 'p' stores the ADDRESS of x (pointer to int)
    *p = 6;           // Changing the value of x through the pointer 'p'

    int** q = &p;     // 'q' is a pointer that stores the ADDRESS of pointer 'p'

    int*** r = &q;    // 'r' is a pointer that stores the ADDRESS of pointer 'q'

    return 0;         // End of program
}

