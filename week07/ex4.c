//
// Created by valentun on 03.10.19.
//

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

// we cannot get actual size of a pointer and preserve portability (because it depends on malloc() implementation
// so we pass it as an 3rd argument
void* my_realloc(void * ptr, size_t old_size, size_t new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void * new_ptr = malloc(new_size);

    size_t min = new_size < old_size ? new_size : old_size;

    if (new_ptr == NULL) {
        return NULL;
    }

    memcpy(new_ptr, ptr, min);

    return new_ptr;
}

int main() {
    //Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = (int *) malloc(sizeof(int) * n1);

    int i;
    for(int i=0; i<n1; i++){
        //Set each value in a1 to 100
        a1[i] =100;

        //Print each element out (to make sure things look right)
        printf("%d ",a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    a1 = my_realloc(a1, sizeof(int ) *n1, sizeof(int) * n2);

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    for (int j = n1; j < n2; ++j) {
        a1[j] = 0;
    }

    for(i=0; i<n2;i++){
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D
    free(a1);
}