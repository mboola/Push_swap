/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Swaps the first two elements of the stack. If the stack has less than
 *	two elements, it does nothing.
 */
void	swap(t_stack *stk)
{
	t_list	*first;
	t_list	*second;

	if (stk->n_elem < 2)
		return ;
	first = pop_top(stk);
	second = pop_top(stk);
	push_top(stk, first);
	push_top(stk, second);
}

void	perform_swap(t_stack *stk)
{
	ft_printf(1, "s%c\n", stk->name);
	swap(stk);
}

void	perform_double_swap(t_stack *stk_a, t_stack *stk_b)
{
	ft_printf(1, "ss\n");
	swap(stk_a);
	swap(stk_b);
}
