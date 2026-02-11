#include <stdio.h>
#include <stdilib.h>
#include <time.h>

typedef struct Set(
	unsigned* array;
unsigned length;
) Set;

Set* set(unsigned
	unsigned* random_generator(unsigned number_of_blocks);
void print(Set* set);
unsigned find_element(Set* set, unsigned element);
Set* Union(Set* A, Set* B);
Set* intersection(Set* A, Set* B);
Set* difference(Set* A, Set* B);
Set* symmetric_difference(Set* A, Set* B);
)