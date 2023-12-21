/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_auxiliary3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/21 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_pivot(t_list *lst)
{
	int	i;
	int	len;
	int	size;

	i = 0;
	size = get_len_to_end(lst);
	len = size / 2;
	while (i < len)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	get_len_to_end(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	get_len_to_start(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->previous != NULL)
	{
		lst = lst->previous;
		i++;
	}
	return (i);
}
