#include "yep.h"

/*The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal*/

/*sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
int *sa(int *a, int *b)
{
	int temp = 0;
	if (a[1] == 0)
		return (NULL);
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	return (a);
}

/*sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
int *sb(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (b[1] == 0)
		return (NULL);
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	return (b);
}

/*ss : sa and sb at the same time.*/
int *ss(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (a[1] == 0 || b[1] == 0)
		return (NULL);
	sa(a,b);
	sb(a,b);
	return (a);
}

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.*/
int *pa(int *a, int *b)
{
	int i = 0;
	if (b[0] == 0)
		return (NULL);
	while (a[i] != 0)
		i++;
	while (i>0)
	{
		a[i] = a[i-1];
		i--;
	}
	a[0] = b[0];
	while (b[i+1] != 0)
	{
		b[i] = b[i+1];
		i++;
	}
	b[i] = 0;
	return (a);
}

/*pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
int *pb(int *a, int *b)
{
	int i = 0;
	if (a[0] == 0)
		return (NULL);
	while (b[i] != 0)
		i++;
	while (i>0)
	{
		b[i] = b[i-1];
		i--;
	}
	b[0] = a[0];
	while (a[i+1] != 0)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = 0;
	return (a);
}

/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
int *ra(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (a[0] == 0)
		return (NULL);
	while (a[i] != 0)
		i++;
	temp = a[0];
	for (int x = 0; x < i; x++)
	{
		a[x] = a[x+1];
	}
	a[i-1] = temp;
	return (a);
}

/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
int *rb(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (b[0] == 0)
		return (NULL);
	while (b[i] != 0)
		i++;
	temp = b[0];
	for (int x = 0; x < i; x++)
	{
		b[x] = b[x+1];
	}
	b[i-1] = temp;
	return (b);
}

/*rr : ra and rb at the same time.*/
int *rr(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (a[0] == 0 || b[0] == 0)
		return (NULL);
	ra(a,b);
	rb(a,b);
	return (a);
}

/*rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.*/
int *rra(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (a[0] == 0)
		return (NULL);
	while (a[i] != 0)
		i++;
	temp = a[i-1];
	for (int x = i-1; x > 0; x--)
	{
		a[x] = a[x-1];
	}
	a[0] = temp;
	return (a);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.*/
int *rrb(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (b[0] == 0)
		return (NULL);
	while (b[i] != 0)
		i++;
	temp = b[i-1];
	for (int x = i-1; x > 0; x--)
	{
		b[x] = b[x-1];
	}
	b[0] = temp;
	return (b);
}

/*rrr : rra and rrb at the same time.*/
int *rrr(int *a, int *b)
{
	int i = 0;
	int temp = 0;
	if (a[0] == 0 || b[0] == 0)
		return (NULL);
	rra(a,b);
	rrb(a,b);
	return (a);
}
