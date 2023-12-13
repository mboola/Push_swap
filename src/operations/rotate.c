
#include "push_swap.h"

/*
 *	Shift up all elements of stack a by 1. The first element becomes the last one.
 */
void	rotate(t_stack *stk)
{
	t_list	*top;

	if (stk->n_elem < 2)
		return ;
	top = pop_top(stk);
	push_bottom(stk, top);
}

void	perform_rotate(t_stack *stk)
{
	printf("r%c\n", stk->name);	//TODO: change to ft_printf();
	rotate(stk);
}

void	perform_double_rotate(t_stack *stk_a, t_stack *stk_b)
{
	printf("rr\n");	//TODO: change to ft_printf();
	rotate(stk_a);
	rotate(stk_b);
}
