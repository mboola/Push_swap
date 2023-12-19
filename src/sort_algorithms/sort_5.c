/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_first_lower(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	if (find_shortest_path(lst))
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
}

/*
 *	Function used to sort 5 elements.
 */
void	sort_5(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	if (is_sorted(stk_a))
		return ;
	sort_first_lower(stk_a, stk_b, lst);
	perform_push(stk_a, stk_b);
	if (get_stk_lst(lst->next) == 'a')
	{
		put_elem_on_top(stk_a, lst->next);
		perform_push(stk_a, stk_b);
	}
	sort_3(stk_a);
	inverse_sort_2(stk_b);
	perform_push(stk_b, stk_a);
	perform_push(stk_b, stk_a);
}
