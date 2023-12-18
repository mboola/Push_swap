//THIS PASSES THE NORMINETTE!!
#include "push_swap.h"

/*
 *	Function used to sort 2 elements.
 */
void	sort_2(t_stack *stk)
{
	if (can_swap(stk))
		perform_swap(stk);
}

void	inverse_sort_2(t_stack *stk)
{
	if (!can_swap(stk))
		perform_swap(stk);
}
