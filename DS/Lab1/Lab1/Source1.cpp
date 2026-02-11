#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_RAND_NUMBERS 100

typedef struct Set {
    unsigned* array;
    unsigned length;
} Set;

// --- Prototypes ---
Set* set(unsigned number_of_blocks);
unsigned* random_generator(unsigned number_of_rand_numbers);
void print(Set* set);
unsigned find_element(Set* set, unsigned element);
Set* Union(Set* A, Set* B);
Set* intersection(Set* A, Set* B);
Set* difference(Set* A, Set* B);
Set* symmetric_difference(Set* A, Set* B);


// --- Implementations ---

unsigned* random_generator(unsigned number_of_blocks) {
    unsigned* array = (unsigned*)malloc(sizeof(unsigned) * number_of_blocks);
    unsigned x, i = 0;

    while (i < number_of_blocks) {
        unsigned r = rand() % NUMBER_OF_RAND_NUMBERS + 1;

        for (x = 0; x < i; x++) {
            if (array[x] == r) {
                break;
            }
        }

        if (x == i) {
            array[i++] = r;
        }
    }
    return array;
}

unsigned find_element(Set* set, unsigned element) {
    unsigned i;
    for (i = 0; i < set->length; i++) {
        if (element == set->array[i]) {
            return 1;
        }
    }
    return 0;
}

Set* set(unsigned number_of_elements) {
    Set* set = (Set*)malloc(sizeof(Set));

    set->array = random_generator(number_of_elements);
    set->length = number_of_elements;
    return set;
}

void print(Set* set) {
    unsigned i;
    for (i = 0; i < set->length; i++) {
        printf("%d\t", set->array[i]);
    }
    printf("\n");
}

Set* intersection(Set* A, Set* B) {
    unsigned i, j, index = 0;

    Set* result_set = (Set*)malloc(sizeof(Set));

    // Note: The slide (image_f58553.jpg) shows: (unsigned*)malloc(sizeof(unsigned));
    // That only allocates space for 1 integer and would crash. 
    // I have corrected it here to A->length to ensure the code runs.
    result_set->array = (unsigned*)malloc(sizeof(unsigned) * A->length);
    result_set->length = 0;

    for (i = 0; i < B->length; i++) {
        for (j = 0; j < A->length; j++) {
            if (A->array[j] == B->array[i]) {
                result_set->array[index++] = A->array[j];
            }
        }
    }
    result_set->length = index;
    return result_set;
}

// Exact implementation from image_f5885c.jpg
Set* Union(Set* A, Set* B) {
    Set* inter = intersection(A, B);
    unsigned i, index, length = A->length + B->length - inter->length;
    free(inter->array);
    free(inter);

    Set* result_set = (Set*)malloc(sizeof(Set));

    result_set->array = (unsigned*)malloc(sizeof(unsigned) * length);
    result_set->length = length;
    for (i = 0; i < A->length; i++) {
        result_set->array[i] = A->array[i];
    }

    index = A->length;

    for (i = 0; i < B->length; i++)
    {
        if (!find_element(A, B->array[i]))
        {
            result_set->array[index++] = B->array[i];
        }
    }

    return result_set;
}

// Exact implementation from image_f588f6.jpg
Set* difference(Set* A, Set* B) {
    Set* inter = intersection(A, B);
    unsigned i, index = 0, length = A->length - inter->length;
    free(inter->array);
    free(inter);

    Set* result_set = (Set*)malloc(sizeof(Set));
    result_set->array = (unsigned*)malloc(sizeof(unsigned) * length);
    result_set->length = length;

    for (i = 0; i < A->length; i++) {
        if (find_element(B, A->array[i]) == 0) {
            result_set->array[index++] = A->array[i];
        }
    }
    // Note: Slide image_f588f6 has a logic hole where it returns result_set 
    // implicitly or the return statement is cut off, but the closing brace is visible.
    // Added return statement to make it valid C.
    return result_set;
}

// Exact implementation from image_f58912.png
Set* symmetric_difference(Set* A, Set* B) {
    // Note: Because Union() reallocs the first parameter's array, 
    // the array belonging to 'difference(A, B)' will be taken over by the result.
    return Union(difference(A, B), difference(B, A));
}