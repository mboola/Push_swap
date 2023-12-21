/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_auxiliary2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/21 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Here we push values higher than pivot to stack B.
 */
int	push_higher_values(t_stack *stk_org, t_stack *stk_dest, t_list *pivot)
{
	int	n_elem;
	int	i;

	n_elem = get_len_to_end(pivot);
	i = n_elem;
	while (n_elem > 0)
	{
		if (get_top_value(stk_org) > get_value_lst(pivot))
		{
			perform_push(stk_org, stk_dest);
			n_elem--;
		}
		else
			perform_rotate(stk_org);
	}
	return (i);
}

void	push_lower_values(t_stack *stk_org, t_stack *stk_dest, t_list *pivot)
{
	int	n_elem;

	n_elem = get_len_to_start(pivot);
	while (n_elem > 0)
	{
		if (get_top_value(stk_org) < get_value_lst(pivot))
		{
			perform_push(stk_org, stk_dest);
			n_elem--;
		}
		else
			perform_rotate(stk_org);
	}
}
