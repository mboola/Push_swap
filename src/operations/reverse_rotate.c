/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Shift down all elements of stack a by 1. 
 *	The last element becomes the first one.
 */
void	reverse_rotate(t_stack *stk)
{
	t_list	*bottom;

	if (stk->n_elem < 2)
		return ;
	bottom = pop_bottom(stk);
	push_top(stk, bottom);
}

void	perform_reverse_rotate(t_stack *stk)
{
	ft_printf(1, "rr%c\n", stk->name);
	reverse_rotate(stk);
}

void	perform_double_reverse_rotate(t_stack *stk_a, t_stack *stk_b)
{
	ft_printf(1, "rrr\n");
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
}
