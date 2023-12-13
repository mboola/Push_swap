
#include "push_swap.h"

/*
 *	Function used to sort 4 elements.
 */
void	sort_4(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	t_list	*node;

	if (is_sorted(stk_a))
		return ;
	if (get_lower_value(lst) == get_top_value(stk_a))
	{
		perform_push(stk_a, stk_b);
		node = extract_first(&lst);
		sort_3(stk_a, lst);
		ft_lstadd_front(&lst, node);
		perform_push(stk_b, stk_a);
	}
	else if(get_higher_value(lst) == get_top_value(stk_a))
	{
		if (!rotate_sorted(stk_a))
		{
			perform_push(stk_a, stk_b);
			node = extract_last(&lst);
			sort_3(stk_a, lst);
			ft_lstadd_back(&lst, node);
			perform_push(stk_b, stk_a);
		}
		perform_rotate(stk_a);
	}
	else if (get_lower_value(lst) == get_bottom_value(stk_a))
	{
		perform_reverse_rotate(stk_a);
		if (!is_sorted(stk_a))
		{
			perform_push(stk_a, stk_b);
			node = extract_first(&lst);
			sort_3(stk_a, lst);
			ft_lstadd_front(&lst, node);
			perform_push(stk_b, stk_a);
		}
	}
	else if (get_higher_value(lst) == get_bottom_value(stk_a))
	{
		perform_reverse_rotate(stk_a);
		perform_push(stk_a, stk_b);
		node = extract_last(&lst);
		sort_3(stk_a, lst);
		ft_lstadd_back(&lst, node);
		perform_push(stk_b, stk_a);
		perform_rotate(stk_a);
	}
	else
	{
		//find lower and put it on top from the lowest path
		if (find_shortest_path(stk_a, lst))
		{
			perform_reverse_rotate(stk_a);
			//do downs
		}
		else
		{
			perform_rotate(stk_a);
			//do ups
		}
		perform_push(stk_a, stk_b);
		node = extract_first(&lst);
		sort_3(stk_a, lst);
		ft_lstadd_front(&lst, node);
		perform_push(stk_b, stk_a);
	}
}
