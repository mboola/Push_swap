/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_values(int *t_val, int *b_val, int *m_val, t_stack *stk)
{
	*t_val = get_top_value(stk);
	*b_val = get_bottom_value(stk);
	*m_val = get_value_stk(stk->bottom_node->next);
}

static int	check_first(int val[], t_stack *stk, char is_inv)
{
	if ((val[0] < val[2] && !is_inv) || (val[0] > val[2] && is_inv))
	{
		if ((val[0] < val[1] && !is_inv) || (val[0] > val[1] && is_inv))
		{
			if ((val[2] > val[1] && !is_inv) || (val[2] < val[1] && is_inv))
			{
				perform_swap(stk);
				perform_rotate(stk);
			}
		}
		else
			perform_reverse_rotate(stk);
		return (1);
	}
	return (0);
}

static void	check_second(int val[], t_stack *stk, char is_inv)
{
	if ((val[0] < val[1] && !is_inv) || (val[0] > val[1] && is_inv))
		perform_swap(stk);
	else
	{
		if ((val[2] > val[1] && !is_inv) || (val[2] < val[1] && is_inv))
		{
			perform_swap(stk);
			perform_reverse_rotate(stk);
		}
		else
			perform_rotate(stk);
	}
}

/*
 *	Function used to sort 3 elements.
 *	I don't like how this ended but it was necessary to pass the norminette.
 */
void	sort_3(t_stack *stk)
{
	int	values[3];

	init_values(&values[0], &values[1], &values[2], stk);
	if (!check_first(values, stk, 0))
		check_second(values, stk, 0);
}

/*
 *	Function used to inverse sort 3 elements.
 */
void	inverse_sort_3(t_stack *stk)
{
	int	values[3];

	init_values(&values[0], &values[1], &values[2], stk);
	if (!check_first(values, stk, 1))
		check_second(values, stk, 1);
}
