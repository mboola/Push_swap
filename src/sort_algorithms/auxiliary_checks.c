
#include "push_swap.h"

/*
 *	Checks if the top two elements of the stack can be swapped.
 */
int		can_swap(t_stack *stk)
{
	t_list	*lst;
	int		first;
	int		second;

	if (stk->n_elem < 2)
		return (0);
	lst = stk->top_node;
	first = get_value_stk(lst);
	lst = lst->previous;
	second = get_value_stk(lst);
	if (first > second)
		return (1);
	return (0);
}

int		can_reverse_rotate(t_stack *stk)
{
	if (stk->n_elem < 2)
		return (0);
	if (get_value_stk(stk->top_node) > get_value_stk(stk->bottom_node))
		return (1);
	return (0);
}

int		is_inverse_sorted(t_stack *stk)
{
	t_list	*lst;
	int		curr_num;
	int		last_num;

	if (stk->n_elem < 2)
		return (1);
	lst = stk->top_node;
	last_num = get_value_stk(lst);
	lst = lst->previous;
	while (lst->previous != NULL)
	{
		curr_num = get_value_stk(lst);
		if (curr_num > last_num)
			return (0);
		last_num = curr_num;
		lst = lst->previous;
	}
	curr_num = get_value_stk(lst);
	if (curr_num > last_num)
		return (0);
	return (1);
}

/*
 *	Checks if the stack is sorted.
 */
int		is_sorted(t_stack *stk)
{
	t_list	*lst;
	int		curr_num;
	int		last_num;

	if (stk->n_elem < 2)
		return (1);
	lst = stk->top_node;
	last_num = get_value_stk(lst);
	lst = lst->previous;
	while (lst->previous != NULL)
	{
		curr_num = get_value_stk(lst);
		if (curr_num < last_num)
			return (0);
		last_num = curr_num;
		lst = lst->previous;
	}
	curr_num = get_value_stk(lst);
	if (curr_num < last_num)
		return (0);
	return (1);
}

/*
 *	Checks if with a swap the stack gets sorted.
 */
int		swap_sorted(t_stack *stk)
{
	int	sorted;

	swap(stk);
	sorted = is_sorted(stk);
	swap(stk);
	return (sorted);
}

/*
 *	Checks if with a rotate the stack gets sorted.
 */
int		rotate_sorted(t_stack *stk)
{
	int	sorted;

	rotate(stk);
	sorted = is_sorted(stk);
	reverse_rotate(stk);
	return (sorted);
}

/*
 *	Checks if with a reverse rotate the stack gets sorted.
 */
int		reverse_rotate_sorted(t_stack *stk)
{
	int	sorted;

	reverse_rotate(stk);
	sorted = is_sorted(stk);
	rotate(stk);
	return (sorted);
}

// not sure about functions below
/*
 *	Used to know if the top element of the stack is higher than the others.
 */
int		can_rotate(t_stack *stk_a)
{
	int		higher;
	size_t	i;

	if (stk_a->n_elem < 2)
		return (0);
	higher = get_num_at(stk_a, 0, 0);
	i = 1;
	while (i < stk_a->n_elem)
	{
		if (higher < get_num_at(stk_a, i, 0))
			return (0);
		i++;
	}
	return (1); 
}

int	is_bottom_higher(t_stack *stk_a)
{
	int		higher;
	size_t	i;

	if (stk_a->n_elem < 2)
		return (0);
	higher = get_num_at(stk_a, 0, 1);
	i = 1;
	while (i < stk_a->n_elem)
	{
		if (higher < get_num_at(stk_a, i, 1))
			return (0);
		i++;
	}
	return (1); 
}



//------------------------------------------------------!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! IDK
/*
 *	Used to know if the top element of the stack is lower than the others.
 */
int	can_push(t_stack *stk_a)
{
	int	lower;
	size_t	i;

	if (stk_a->n_elem < 2)
		return (0);
	lower = get_num_at(stk_a, 0, 0);
	i = 1;
	while (i < stk_a->n_elem)
	{
		if (lower > get_num_at(stk_a, i, 0))
			return (0);
		i++;
	}
	return (1); 
}


