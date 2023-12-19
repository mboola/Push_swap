/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/14 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if going down is the fastest path it returns 1, if not returns 0
int		find_shortest_path(t_list *node)
{
	int		steps_r;
	int		steps_rr;
	t_list	*lst;

	steps_rr = 0;
	steps_r = 0;
	lst = (t_list *)(node->content);
	while(lst->next != NULL)
	{
		lst = lst->next;
		steps_r++;
	}
	lst = (t_list *)(node->content);
	while(lst->previous != NULL)
	{
		lst = lst->previous;
		steps_rr++;
	}
	steps_rr++;
	if (steps_rr < steps_r)
		return (1);
	return (0);
}

int	get_value_stk(t_list *stk_lst)
{
	int	number;

	number = ((t_node *)(stk_lst->content))->number;
	return (number);
}

int	get_bottom_value(t_stack *stk)
{
	return (get_value_stk(stk->bottom_node));
}

int	get_top_value(t_stack *stk)
{
	return (get_value_stk(stk->top_node));
}

t_stack *create_stack(char name, char *err)
{
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
	if (!stk)
	{
		*err = 1;
		return (NULL);
	}
	stk->name = name;
	stk->top_node = NULL;
	stk->bottom_node = NULL;
	stk->n_elem = 0;
	return (stk);
}
