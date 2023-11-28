
#include "push_swap.h"

t_stack *create_stack(char name, int *err)
{
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
	if (!stk)
	{
		*err = 1;
		return (NULL);
	}
	stk->name = name;
	stk->nodes = NULL;
	stk->n_elem = 0;
	return (stk);
}
