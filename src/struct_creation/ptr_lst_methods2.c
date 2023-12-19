/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_lst_methods2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/14 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Returns the value of the node the content of this lst is pointing to.
 */
int	get_value_lst(t_list *ptr_lst)
{
	int		number;
	t_list	*lst;
	t_node	*node;

	lst = (t_list *)(ptr_lst->content);
	node = (t_node *)(lst->content);
	number = node->number;
	return (number);
}

/*
 *	Returns the stack_name the content of this lst is pointing to.
 */
int	get_stk_lst(t_list *ptr_lst)
{
	int		name;
	t_list	*lst;
	t_node	*node;

	lst = (t_list *)(ptr_lst->content);
	node = (t_node *)(lst->content);
	name = node->stack_name;
	return (name);
}

/*
 *	Creates a linked list of pointers to nodes of a stack.
 */
t_list	*create_lst_ptr_to_nodes(t_stack *stk, char *err)
{
	t_list	*ptr_lst;
	t_list	*ptr_node;
	t_list	*nodes;

	ptr_lst = NULL;
	nodes = stk->bottom_node;
	while (nodes->next != NULL)
	{
		ptr_node = ft_lstnew(nodes);
		if (!ptr_node)
		{
			*err = 1;
			return (clear_ptr_lst(&ptr_lst));
		}
		ft_lstadd_back(&ptr_lst, ptr_node);
		nodes = nodes->next;
	}
	ptr_node = ft_lstnew(&(nodes->content));
	if (!ptr_node)
	{
		*err = 1;
		return (clear_ptr_lst(&ptr_lst));
	}
	ft_lstadd_back(&ptr_lst, ptr_node);
	return (ptr_lst);
}
