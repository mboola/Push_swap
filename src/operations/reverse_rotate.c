
#include "push_swap.h"

/*
 *	Shift down all elements of stack a by 1. The last element becomes the first one.
 */
static void	reverse_rotate(t_stack *stk)
{
	t_list	*bottom;

	if (stk->n_elem < 2)
		return ;
	bottom = pop_bottom(stk);
	push_top(stk, bottom);
}

void	perform_reverse_rotate(t_stack *stk)
{
	printf("rr%c\n", stk->name);	//TODO: change to ft_printf();
	reverse_rotate(stk);
}

void	perform_double_reverse_rotate(t_stack *stk_a, t_stack *stk_b)
{
	printf("rrr\n");	//TODO: change to ft_printf();
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
}
