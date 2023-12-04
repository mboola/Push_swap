
#include "push_swap.h"

void	swap(t_stack *stk)
{
	t_list	*top;
	t_list	*bottom;

	if (stk == NULL || stk->n_elem < 2)
		return ;
	top = extract_first(stk->nodes);
	bottom = extract_first(stk->nodes);
	
}

t_list	*pop(t_stack *stk)
{

}

void	push(t_stack *stk)
{

}

void	rotate(t_stack *stk)
{

}

void	reverse_rotate(t_stack *stk)
{

}

void	swap_both(t_stack *stk_a, t_stack *stk_b)
{
	swap(stk_a);
	swap(stk_b);
}

void	push_both(t_stack *stk_a, t_stack *stk_b)
{
	push(stk_a);
	push(stk_b);
}

void	rotate_both(t_stack *stk_a, t_stack *stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
}

void	reverse_rotate_both(t_stack *stk_a, t_stack *stk_b)
{
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
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
	stk->first_node = NULL;
	stk->last_node = NULL;
	stk->n_elem = 0;
	return (stk);
}
