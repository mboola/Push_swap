
#include "push_swap.h"

/*
 *	Function used to sort 2 elements.
 */
void	sort_2(t_stack *stk_a)
{
	if (can_swap(stk_a))
		perform_swap(stk_a);
}
