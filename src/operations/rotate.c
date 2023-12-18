//THIS PASSES THE NORMINETTE!!
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
	ft_printf("r%c\n", stk->name);
	rotate(stk);
}

void	perform_double_rotate(t_stack *stk_a, t_stack *stk_b)
{
	ft_printf("rr\n");
	rotate(stk_a);
	rotate(stk_b);
}
