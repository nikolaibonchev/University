#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Set {
	char* array;
	unsigned length;
} Set;

typedef struct Pair {
	unsigned x;
	unsigned y;
} Pair;

typedef struct Relation {
	Pair* pairs;
	unsigned length;
} Relation;

unsigned* random_generator(unsigned numbers, unsigned max, unsigned min);
Set* set(unsigned number_of_elements, unsigned max, unsigned min);
void print(Set* set);
Relation* cartesian_product(Set* A, Set* B);
void print_cartesian_product(Relation* cartesian_product);

unsigned find_element(Relation* relation, Pair pair);
unsigned find_element_sets(Set* set, unsigned element);