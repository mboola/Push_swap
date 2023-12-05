
#include "push_swap.h"

/*
 *	Function used to sort 3 elements.
 */
void	sort_3(t_stack *stk_a)
{
	if (can_rotate(stk_a))
		perform_rotate(stk_a);
	if (can_swap(stk_a))
		perform_swap(stk_a);
	if (can_reverse_rotate(stk_a))
		perform_reverse_rotate(stk_a);
	if (!is_bottom_higher(stk_a))
	{
		perform_swap(stk_a);
		perform_rotate(stk_a);
	}
}
