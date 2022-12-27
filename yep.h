#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int *(*operation)(int *, int *);

struct jump_table {
	char* key;
	operation value;
};

int *sa(int *a, int *b);
int *sb(int *a, int *b);
int *ss(int *a, int *b);
int *pa(int *a, int *b);
int *pb(int *a, int *b);
int *ra(int *a, int *b);
int *rb(int *a, int *b);
int *rr(int *a, int *b);
int *rra(int *a, int *b);
int *rrb(int *a, int *b);
int *rrr(int *a, int *b);
