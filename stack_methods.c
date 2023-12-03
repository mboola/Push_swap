
#include "push_swap.h"

void	perform_sa(t_stack *stk)
{

}

int		get_n_elem(t_stack	*stk, int index)
{
	t_list	*lst;
	int		i;

	if (stk->n_elem < index)
	{
		printf("Index greater than n_elem when searching nodes from stack");
		return (0);
	}
	lst = stk->nodes;
	i = 0;
	while (i < index)
		lst = lst->next;
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
	stk->nodes = NULL;
	stk->n_elem = 0;
	return (stk);
}
