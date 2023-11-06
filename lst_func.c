/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:17:17 by mpovill-          #+#    #+#             */
/*   Updated: 2023/11/06 19:17:18 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstnew(int *content, int *err)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		*err = -1;
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_create_node(int content, int *err)
{
	int	*value;

	value = malloc(sizeof(int));
	if (value == NULL)
	{
		*err = -1;
		return (NULL);
	}
	*value = content;
	return (ft_lstnew(value, err));
}
