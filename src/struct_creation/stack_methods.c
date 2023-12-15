
#include "push_swap.h"

//if going down is the fastest path it returns 1, if not returns 0
int	find_shortest_path(t_stack *stk, t_list *node)
{
	int		steps_r;
	int		steps_rr;
	t_list	*lst;

	steps_rr = 0;
	steps_r = 0;
	lst = (t_list *)(node->content);
	//first we look rotate (up)
	while(lst->next != NULL)
	{
		lst = lst->next;
		steps_r++;
	}
	lst = (t_list *)(node->content);
	while(lst->previous != NULL)
	{
		lst = lst->previous;
		steps_rr++;
	}
	steps_rr++;
	//printf("Steps r are: %d and Steps rr are: %d\n", steps_r, steps_rr);
	if (steps_rr < steps_r)
		return (1);
	return (0);
}

int	get_value_stk(t_list *stk_lst)
{
	int	number;

	number = ((t_node *)(stk_lst->content))->number;
	return (number);
}

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
	return (get_value_stk(lst));
}

int	get_bottom_value(t_stack *stk)
{
	return (get_value_stk(stk->bottom_node));
}

int	get_top_value(t_stack *stk)
{
	return (get_value_stk(stk->top_node));
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
