/***********************************************************************************************
 *This files show the 5 ways of Reversing Array in c
 * C Program to 
 * 1.Reverse an Array Using for Loop
 * 2.Array Reverse in C Using while Loop
 * 3.Reverse Array in C Using Recursion
 * 4.Array Reversal in C Using Temporary Array
 * 5.Array Reversal in C Using Pointer Arithmetic
 ******************************************************************************************************
*/

#include <stdio.h>

// Reverse using FOR loop
void reverseFor(int arr[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Reverse using WHILE loop
void reverseWhile(int arr[], int n) {
    int start = 0, end = n - 1, temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Reverse using RECURSION
void reverseRecursion(int arr[], int start, int end) {
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseRecursion(arr, start + 1, end - 1);
}

//Reverse using TEMP ARRAY
void reverseTempArray(int arr[], int n) {
    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[i] = arr[n - i - 1];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

//Reverse using POINTERS 
void reversePointer(int *start, int *end) {
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

//Print Function
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//MAIN FUNCTION
int main() {

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], copy[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        copy[i] = arr[i];   // backup to restore later
    }

    printf("\n--- Method 1: FOR Loop ---\n");
    reverseFor(arr, n);
    printArray(arr, n);

    // Restore original
    for (int i = 0; i < n; i++) arr[i] = copy[i];

    printf("\n--- Method 2: WHILE Loop ---\n");
    reverseWhile(arr, n);
    printArray(arr, n);

    // Restore original
    for (int i = 0; i < n; i++) arr[i] = copy[i];

    printf("\n--- Method 3: Recursion ---\n");
    reverseRecursion(arr, 0, n - 1);
    printArray(arr, n);

    // Restore original
    for (int i = 0; i < n; i++) arr[i] = copy[i];

    printf("\n--- Method 4: Temporary Array ---\n");
    reverseTempArray(arr, n);
    printArray(arr, n);

    // Restore original
    for (int i = 0; i < n; i++) arr[i] = copy[i];

    printf("\n--- Method 5: Pointer Arithmetic ---\n");
    reversePointer(arr, arr + n - 1);
    printArray(arr, n);

    return 0;
}
