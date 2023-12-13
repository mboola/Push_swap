
#include "push_swap.h"

/*
 *	Function used to sort 3 elements.
 */
void	sort_3(t_stack *stk_a, t_list *sorted_list)
{
	int	higher;
	int	lower;

	higher = get_higher_value(sorted_list);
	lower = get_lower_value(sorted_list);
	if (get_top_value(stk_a) == lower)
	{
		if (get_bottom_value(stk_a) != higher)
		{
			perform_swap(stk_a);
			perform_rotate(stk_a);
		}
	}
	else if (get_top_value(stk_a) == higher)
	{
		if (get_bottom_value(stk_a) == lower)
		{
			perform_swap(stk_a);
			perform_reverse_rotate(stk_a);
		}
		else
			perform_rotate(stk_a);
	}
	else if (get_bottom_value(stk_a) == lower)
		perform_reverse_rotate(stk_a);
	else
		perform_swap(stk_a);
}
