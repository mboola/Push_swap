
#include "push_swap.h"

/*
 *	Function used to sort n elements.
 */
void	sort_n(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	t_list	*curr_value;

	curr_value = lst;
	if (is_sorted(stk_a))
		return ;
	//first we get the lowest number on top with the shortest path, putting all on b
	if (find_shortest_path(stk_a, lst))
		while (get_top_value(stk_a) != get_lower_value(lst))
			perform_push(stk_a, stk_b);
	else
		while (get_top_value(stk_a) != get_lower_value(lst))
			perform_reverse_rotate(stk_a);
	perform_rotate(stk_a);
	while (!is_sorted(stk_a) || stk_b->n_elem != 0)
	{
		curr_value = curr_value->next;
		if (get_stk_lst(curr_value) == 'a')
			while (get_top_value(stk_a) != get_lower_value(curr_value))
				perform_push(stk_a, stk_b);
		else
		{
			if (find_shortest_path(stk_b, curr_value))
				while (get_top_value(stk_b) != get_lower_value(curr_value))
					perform_reverse_rotate(stk_b);
			else
				while (get_top_value(stk_b) != get_lower_value(curr_value))
					perform_rotate(stk_b);
			perform_push(stk_b, stk_a);
		}
		perform_rotate(stk_a);
	}
}
