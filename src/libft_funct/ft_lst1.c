/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*extract_last(t_list **lst)
{
	t_list	*new_last;
	t_list	*lst_iter;

	if (*lst == NULL)
		return (NULL);
	lst_iter = *lst;
	new_last = NULL;
	while (lst_iter->next != NULL)
	{
		new_last = lst_iter;
		lst_iter = lst_iter->next;
	}
	if (new_last != NULL)
		new_last->next = NULL;
	else
		*lst = NULL;
	lst_iter->previous = NULL;
	return (lst_iter);
}

t_list	*extract_first(t_list **lst)
{
	t_list	*first;

	first = *lst;
	*lst = (*lst)->next;
	if (*lst != NULL)
		(*lst)->previous = NULL;
	first->next = NULL;
	return (first);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		(*lst)->previous = new;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		if (new != NULL)
			new->previous = last;
		last->next = new;
	}
}
