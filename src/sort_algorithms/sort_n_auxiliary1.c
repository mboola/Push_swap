/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_auxiliary1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/21 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_values_sorted(t_stack *stk_origin, t_stack *stk_dest, int n_elem)
{
	int	i;

	i = 0;
	if (stk_origin->n_elem == 0)
		return (0);
	while (stk_origin->n_elem - n_elem > 1)
	{
		perform_reverse_rotate(stk_origin);
		perform_push(stk_origin, stk_dest);
		i++;
	}
	i++;
	perform_push(stk_origin, stk_dest);
	return (i);
}

int	push_values_invsorted(t_stack *stk_org, t_stack *stk_dest, int n_elem)
{
	int	i;

	i = 0;
	while (stk_org->n_elem - n_elem > 0)
	{
		perform_push(stk_org, stk_dest);
		i++;
	}
	return (i);
}

void	rotate_elem(t_stack *stk, int n_elem)
{
	int	i;

	i = 0;
	while (i < n_elem)
	{
		perform_rotate(stk);
		i++;
	}
}

void	push_elem(t_stack *stk_a, t_stack *stk_b, int n_elem)
{
	int i;

	i = 0;
	while (i < n_elem)
	{
		perform_push(stk_a, stk_b);
		i++;
	}
}
