//THIS PASSES THE NORMINETTE!!
#include "push_swap.h"

static void	push_and_sort(t_stack *stk_a, t_stack *stk_b)
{
	perform_push(stk_a, stk_b);
	sort_3(stk_a);
	perform_push(stk_b, stk_a);
}

/*
 *	Checks if with a rotate the stack gets sorted.
 */
static int	rotate_sorted(t_stack *stk)
{
	int	sorted;

	rotate(stk);
	sorted = is_sorted(stk);
	reverse_rotate(stk);
	return (sorted);
}

/*
 *	Finds first element and put its on top. 
 *	Redundant but necessary to pass norminette.
 */
static void	sort_last_case(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	put_elem_on_top(stk_a, lst);
	push_and_sort(stk_a, stk_b);
}

/*
 *	Function used to sort 4 elements.
 */
void	sort_4(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	if (is_sorted(stk_a))
		return ;
	if (get_lower_value(lst) == get_top_value(stk_a))
		push_and_sort(stk_a, stk_b);
	else if (get_higher_value(lst) == get_top_value(stk_a))
	{
		if (!rotate_sorted(stk_a))
			push_and_sort(stk_a, stk_b);
		perform_rotate(stk_a);
	}
	else if (get_lower_value(lst) == get_bottom_value(stk_a))
	{
		perform_reverse_rotate(stk_a);
		if (!is_sorted(stk_a))
			push_and_sort(stk_a, stk_b);
	}
	else if (get_higher_value(lst) == get_bottom_value(stk_a))
	{
		perform_reverse_rotate(stk_a);
		push_and_sort(stk_a, stk_b);
		perform_rotate(stk_a);
	}
	else
		sort_last_case(stk_a, stk_b, lst);
}
