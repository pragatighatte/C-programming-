
In call by value, a copy of the variable's value is passed to the function.
Any changes made to the variable inside the function do not affect the original variable outside the function,
because the function is working on a separate copy.
The variable in the calling function and the variable in the called function are distinct, even if they have the same name.

In call by reference, the address of the variable is passed to the function using pointers.
This allows the function to directly access and modify the original variable's value in memory.
Changes made inside the function will reflect on the original variable outside the function.
