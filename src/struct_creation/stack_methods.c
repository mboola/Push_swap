
#include "push_swap.h"

int		get_num_at(t_stack *stk, size_t index, int from_bottom)
{
	t_list	*lst;
	size_t	i;

	if (stk->n_elem < index)
	{
		printf("Index greater than n_elem when searching nodes from stack");
		return (0);
	}
	if (from_bottom)
		lst = stk->bottom_node;
	else
		lst = stk->top_node;
	i = 0;
	if (from_bottom)
		while (i < index)
		{
			lst = lst->next;
			i++;
		}
	else
		while (i < index)
		{
			lst = lst->previous;
			i++;
		}
	return (get_node_number_from_lst(lst));
}

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
	stk->top_node = NULL;
	stk->bottom_node = NULL;
	stk->n_elem = 0;
	return (stk);
}
