
#include "push_swap.h"

/*
 *	Used to know if the top two elements of the stack should be swapped.
 */
int		can_swap(t_stack *stk_a)
{
	if (stk_a->n_elem < 2)
		return (0);
	if (get_num_at(stk_a, 0, 0) > get_num_at(stk_a, 1, 0))
		return (1);
	return (0);
}

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

/*
 *	Used to know if the bottom element of the stack is lower than the others.
 */
int	can_reverse_rotate(t_stack *stk_a)
{
	int		lower;
	size_t	i;

	if (stk_a->n_elem < 2)
		return (0);
	lower = get_num_at(stk_a, 0, 1);
	i = 1;
	while (i < stk_a->n_elem)
	{
		if (lower > get_num_at(stk_a, i, 1))
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
