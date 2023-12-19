/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stk_a, t_stack **stk_b, t_list **sorted_list)
{
	if ((*stk_a)->n_elem > 5)
		sort_n(*stk_a, *stk_b, *sorted_list);
	else if ((*stk_a)->n_elem == 5)
		sort_5(*stk_a, *stk_b, *sorted_list);
	else if ((*stk_a)->n_elem == 4)
		sort_4(*stk_a, *stk_b, *sorted_list);
	else if ((*stk_a)->n_elem == 3)
		sort_3(*stk_a);
	else if ((*stk_a)->n_elem == 2)
		sort_2(*stk_a);
	clear_data(stk_a, stk_b, sorted_list);
}
