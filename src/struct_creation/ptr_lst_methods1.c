/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_lst_methods1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/14 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if going down is the fastest path it returns 1, if not returns 0
int	find_shortest_path(t_list *node)
{
	int		steps_r;
	int		steps_rr;
	t_list	*lst;

	steps_rr = 0;
	steps_r = 0;
	lst = (t_list *)(node->content);
	while (lst->next != NULL)
	{
		lst = lst->next;
		steps_r++;
	}
	lst = (t_list *)(node->content);
	while (lst->previous != NULL)
	{
		lst = lst->previous;
		steps_rr++;
	}
	steps_rr++;
	if (steps_rr < steps_r)
		return (1);
	return (0);
}

int	find_inside_lst(t_list *lst, int num)
{
	int	i;

	i = 0;
	while (get_value_lst(lst) != num)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	get_higher_value(t_list *lst)
{
	return (get_value_lst(ft_lstlast(lst)));
}

int	get_lower_value(t_list *lst)
{
	return (get_value_lst(lst));
}
