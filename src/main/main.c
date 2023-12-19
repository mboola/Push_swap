/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	clear_and_exit(t_stack **stk_a, t_stack **stk_b)
{
	ft_printf(2, ERROR_MSG);
	clear_stack(stk_a);
	clear_stack(stk_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_list	*ptr_to_nodes;
	char	err;

	if (argc == 1)
		return (0);
	err = 0;
	stk_a = create_stack('a', &err);
	stk_b = create_stack('b', &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	initialize_stk_elem(argc, argv, stk_a, &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	ptr_to_nodes = create_lst_ptr_to_nodes(stk_a, &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	ptr_to_nodes = quick_sort(ptr_to_nodes, &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	push_swap(&stk_a, &stk_b, &ptr_to_nodes);
	return (0);
}
