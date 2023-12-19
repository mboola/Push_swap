/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Checks if the top two elements of the stack can be swapped.
 */
int	can_swap(t_stack *stk)
{
	t_list	*lst;
	int		first;
	int		second;

	if (stk->n_elem < 2)
		return (0);
	lst = stk->top_node;
	first = get_value_stk(lst);
	lst = lst->previous;
	second = get_value_stk(lst);
	if (first > second)
		return (1);
	return (0);
}

int	is_inverse_sorted(t_stack *stk)
{
	t_list	*lst;
	int		curr_num;
	int		last_num;

	if (stk->n_elem < 2)
		return (1);
	lst = stk->top_node;
	last_num = get_value_stk(lst);
	lst = lst->previous;
	while (lst->previous != NULL)
	{
		curr_num = get_value_stk(lst);
		if (curr_num > last_num)
			return (0);
		last_num = curr_num;
		lst = lst->previous;
	}
	curr_num = get_value_stk(lst);
	if (curr_num > last_num)
		return (0);
	return (1);
}

/*
 *	Checks if the stack is sorted.
 */
int	is_sorted(t_stack *stk)
{
	t_list	*lst;
	int		curr_num;
	int		last_num;

	if (stk->n_elem < 2)
		return (1);
	lst = stk->top_node;
	last_num = get_value_stk(lst);
	lst = lst->previous;
	while (lst->previous != NULL)
	{
		curr_num = get_value_stk(lst);
		if (curr_num < last_num)
			return (0);
		last_num = curr_num;
		lst = lst->previous;
	}
	curr_num = get_value_stk(lst);
	if (curr_num < last_num)
		return (0);
	return (1);
}

/*
 *	Checks if with a swap the stack gets sorted.
 */
int	swap_sorted(t_stack *stk)
{
	int	sorted;

	swap(stk);
	sorted = is_sorted(stk);
	swap(stk);
	return (sorted);
}
