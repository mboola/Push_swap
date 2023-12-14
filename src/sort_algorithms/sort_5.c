
#include "push_swap.h"

/*
 *	Function used to sort 5 elements.
 */
void	sort_5(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	t_list	*tmp;

	if (find_shortest_path(stk_a, lst))
	{
		while (get_top_value(stk_a) != get_lower_value(lst))
		{
			if (get_top_value(stk_a) == get_value_lst(lst->next))
				perform_push(stk_a, stk_b);
			perform_reverse_rotate(stk_a);
		}
	}
	else
	{
		while (get_top_value(stk_a) != get_lower_value(lst))
		{
			if (get_top_value(stk_a) == get_value_lst(lst->next))
				perform_push(stk_a, stk_b);
			else
				perform_rotate(stk_a);
		}
	}
	perform_push(stk_a, stk_b);
	if (get_stk_lst(lst->next) == 'a')
	{
		put_elem_on_top(stk_a, lst->next);
		perform_push(stk_a, stk_b);
	}

	tmp = lst->next->next;
	tmp->previous = NULL;
	lst->next->next = NULL;

	//separate lst into two
	sort_3(stk_a, tmp);
	reverse_sort_2(stk_b);

	ft_lstadd_back(&lst, tmp);

	perform_push(stk_b, stk_a);
	perform_push(stk_b, stk_a);
}
