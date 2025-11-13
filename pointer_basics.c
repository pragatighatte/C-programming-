*/
  Key points explained inline:
  - pointer declaration and initialization
  - address vs value (use %p for addresses)
  - dereferencing
  - pointer arithmetic (p + 1 moves by sizeof(*p))
  - casting an int* to char* to examine individual bytes (endianness)
  - use sizeof with %zu
*/

int main(void) {
    /* ---------- basic int and pointer setup ---------- */

    int a = 10;          // an integer variable
    int *p = &a;         // p holds the address of 'a' (type: pointer-to-int)

    /* Print addresses with %p (portable) and values with %d */

    printf("address stored in p (p)       = %p\n", (void *)p);
    printf("value pointed to by p (*p)    = %d\n", *p);
    printf("address of a (&a)             = %p\n", (void *)&a);
    printf("address of pointer variable p (&p) = %p\n\n", (void *)&p);

    /* ---------- modifying value through pointer ---------- */

    *p = 12;// change the value of 'a' via pointer dereference
    printf("after *p = 12, a = %d\n\n", a);

    /* ---------- assign another integer to the location pointed by p ---------- */
    int b = 20;
    *p = b; // copies b's value into the int object pointed by p (i.e. into a)
    printf("after *p = b (b = 20), *p  = %d\n", *p);
    printf("pointer p still at address= %p\n\n", (void *)p);

    /* ---------- pointer address and value printing again ---------- */
    a = 10;              // set a back to 10 to demonstrate pointer arithmetic below
    printf("address of p (&p)             = %p\n", (void *)&p);
    printf("value at address p (*p)       = %d\n", *p);

    /* sizeof returns size_t - print with %zu */
    printf("size of int (sizeof(int))     = %zu bytes\n\n", sizeof(int));

    /* ---------- pointer arithmetic ---------- */
    /* p + 1 points to the next int in memory (advances by sizeof(int) bytes) */

    printf("address p + 1 (p + 1)         = %p\n", (void *)(p + 1));

    /* Dereferencing p+1 reads the int at that next location - may be garbage if nothing allocated there */

    printf("value at (p + 1) (*(p + 1))   = %d  (may be garbage / undefined if not initialized)\n\n", *(p + 1));

    /* ---------- examine bytes of an int via char* (type punning) ---------- */

    a = 1025; // 1025 = 0x00000401 on a little-endian 32-bit/64-bit system
    printf("set a = %d\n", a);
    printf("address of p (again) = %p\n", (void *)p);
    printf("value at p (*p) = %d\n\n", *p);

    /*
      Cast int* to char* to inspect individual bytes.
      - char* steps through memory one byte at a time.
      - Behavior reveals endianness: on little-endian systems, lowest-significant byte is at lowest address.
      - Use (unsigned char) when printing numeric byte values to avoid sign-extension issues.
    */
    char *p0 = (char *)p;   // reinterpret the address of the int as a pointer to bytes
    printf("size of char (sizeof(char))   = %zu bytes\n", sizeof(char));

    /* print the address of p0 and the first byte value */

    printf("address stored in p0           = %p\n", (void *)p0);
    printf("value at p0 (first byte)      = %u  (unsigned byte)\n", (unsigned char) *p0);

    /* p0 + 1 is the next byte; print its address and value */

    printf("address p0 + 1                = %p\n", (void *)(p0 + 1));
    printf("value at *(p0 + 1)            = %u  (unsigned byte)\n\n", (unsigned char) *(p0 + 1));

    /*
      NOTE:
      - Accessing *(p + 1) earlier and these byte-values can be undefined if those memory locations
        are outside the object you legitimately own. In this simple program we examine the next
        bytes in the same int 'a', which is safe because the char* walks inside the 'a' object.
      - Printing pointer values must use %p and cast to (void *) for portability.
      - Printing sizes should use %zu.
    */

    return 0;
}

