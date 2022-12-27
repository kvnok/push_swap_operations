#include "yep.h"

struct jump_table functions[] = {
	{"sa", sa},
	{"sb", sb},
	{"ss", ss},
	{"pa", pa},
	{"pb", pb},
	{"ra", ra},
	{"rb", rb},
	{"rr", rr},
	{"rra", rra},
	{"rrb", rrb},
	{"rrr", rrr},
	{NULL, NULL}
};

int main(int argc, char **argv) {
	if (argc < 2) 
	{
		printf("Error: No input provided.\n");
		return 1;
	}
	int *a;
	int *b;
	a = calloc((argc + 1) * sizeof(int), 1);
	b = calloc((argc + 1) * sizeof(int), 1);
	printf("STACKS LOADED IN\n");
	printf("a b\n");
	printf("----\n");
	for (int i = 1; i < argc; i++)
	{
		a[i - 1] = atoi(argv[i]);
		if (a[i-1] != 0)
			printf("%d ", a[i-1]);
		if (b[i-1] != 0)
			printf("%d", b[i-1]);
		printf("\n");
	}
	while(1)
	{
		char input[5];
		operation func = NULL;
		printf("\nchoose operation: ");
		scanf("%s", input);
		for (int i = 0; functions[i].key != NULL; i++)
		{
			if (strcmp(functions[i].key, input) == 0)
			{
				func = functions[i].value;
				break;
			}
		}
		if (func == NULL)
		{
			printf("Error: Invalid input provided.\n");
			return 1;
		}
		if (func(a, b) == NULL)
		{
			printf("DOES NOT WORK WITH THIS DATA\n");
			continue;
		}
		printf("UPDATED STACKS\n");
		printf("a b\n");
		printf("----\n");
		for (int i = 1; a[i-1] != 0 || b[i-1] != 0; i++)
		{
			if (a[i-1] != 0)
				printf("%d ", a[i-1]);
			if (b[i-1] != 0)
				printf("%d", b[i-1]);
			printf("\n");
		}
	}
	return 0;
}
