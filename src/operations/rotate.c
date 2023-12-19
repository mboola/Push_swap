/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Shift up all elements of stack a by 1. The first element becomes the last one.
 */
void	rotate(t_stack *stk)
{
	t_list	*top;

	if (stk->n_elem < 2)
		return ;
	top = pop_top(stk);
	push_bottom(stk, top);
}

void	perform_rotate(t_stack *stk)
{
	ft_printf(1, "r%c\n", stk->name);
	rotate(stk);
}

void	perform_double_rotate(t_stack *stk_a, t_stack *stk_b)
{
	ft_printf(1, "rr\n");
	rotate(stk_a);
	rotate(stk_b);
}
