/* C code create a custom memcpy function to transfer multiple bytes*/
/* Author: Mehul Shah */

#include <stdio.h>
#include <stdint.h>

void memCpy(void* dest, const void* source, int size)
{
    while(size >= sizeof(size_t))
    {
        *(size_t*) dest = *(const size_t*)source; // This helps us copying 4/8 bytes of data at a time, instead of 1
        dest += sizeof(size_t);
        source += sizeof(size_t);
        size -= sizeof(size_t);                   // Decrement by 4
    }

    char* dest_byte = (char*)dest;                    // Convert to char* for copying remaining bytes, 1 byte at a time
    const char* source_byte = (const char*)source;

        while(size > 0)
        {
            *dest_byte++ = *source_byte++;
            size--;
        }
}

int main(void){

    char source[] = "Hello, my name is Mehul!";
    int size = sizeof(source)/sizeof(source[0]);
    char dest[size];

    printf("Destination before custom memCpy: '%s'\n", dest);

    memCpy(dest, source, size);

    printf("After memCpy: '%s'", dest);

    return 0;
}
