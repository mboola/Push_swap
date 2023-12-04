
#include "push_swap.h"

/*
 *	Swaps the first two elements of the stack. If the stack has less than
 *	two elements, it does nothing.
 */
static void	swap(t_stack *stk)
{
	t_list	*first;
	t_list	*second;

	if (stk->n_elem < 2)
		return ;
	first = pop_top(stk);
	second = pop_top(stk);
	push_top(stk, first);
	push_top(stk, second);
}

void	perform_swap(t_stack *stk)
{
	printf("p%c\n", stk->name);	//TODO: change to ft_printf();
	swap(stk);
}

void	perform_double_swap(t_stack *stk_a, t_stack *stk_b)
{
	printf("ss\n");	//TODO: change to ft_printf();
	swap(stk_a);
	swap(stk_b);
}
