/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	clear_all(t_list **fst, t_list **scnd, t_list **pvt, t_list **lst)
{
	if (fst && *fst)
		clear_ptr_lst(fst);
	if (scnd && *scnd)
		clear_ptr_lst(scnd);
	if (pvt && *pvt)
		clear_ptr_lst(pvt);
	if (lst && *lst)
		clear_ptr_lst(lst);
	return (1);
}

static t_list	*clear_lsts(t_list **lst, t_list **pvt)
{
	clear_all(lst, pvt, NULL, NULL);
	return (NULL);
}

/*
 *	Distributes the nodes of a linked list of pointers in two based if they are
 *	higher or lower from a pvt. If they are equal, an error is returned and
 *	everything is cleaned.
 */
static int	dstrb_elem(t_list **fst, t_list **scnd, t_list **pvt, t_list **lst)
{
	int		pvt_num;
	int		current_number;

	if (*lst == NULL || *pvt == NULL)
		return (0);
	pvt_num = get_value_lst(*pvt);
	while ((*lst)->next != NULL)
	{
		current_number = get_value_lst(*lst);
		if (current_number < pvt_num)
			ft_lstadd_back(fst, extract_first(lst));
		else if (current_number > pvt_num)
			ft_lstadd_back(scnd, extract_first(lst));
		else
			return (clear_all(fst, scnd, pvt, lst));
	}
	current_number = get_value_lst(*lst);
	if (current_number < pvt_num)
		ft_lstadd_back(fst, extract_first(lst));
	else if (current_number > pvt_num)
		ft_lstadd_back(scnd, extract_first(lst));
	else
		return (clear_all(fst, scnd, pvt, lst));
	return (0);
}

/*
 *	This method sorts the *lst from lesser to greater.
 *	Because lst is a list of pointers to nodes, sorting this list will have
 *	no effect on the elements of a stack it points to.
 *	We will also check if this list has repeated numbers, and will set
 *	*err as 1 if there are. It will also clean everything that used.
 */
t_list	*quick_sort(t_list *lst, char *err)
{
	t_list	*fst;
	t_list	*scnd;
	t_list	*pvt;

	fst = NULL;
	scnd = NULL;
	pvt = extract_last(&lst);
	if (dstrb_elem(&fst, &scnd, &pvt, &lst))
	{
		*err = 1;
		return (NULL);
	}
	if (fst)
		fst = quick_sort(fst, err);
	if (*err)
		return (clear_lsts(&scnd, &pvt));
	ft_lstadd_back(&fst, pvt);
	if (scnd)
		scnd = quick_sort(scnd, err);
	if (*err)
		return (clear_lsts(&fst, NULL));
	ft_lstadd_back(&fst, scnd);
	return (fst);
}
