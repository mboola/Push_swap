/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/21 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack *stk_a, t_stack *stk_b, t_list *lst, char ign_sorted);
static int	sort_half(t_stack *stk_a, t_stack *stk_b, t_list *lst);

static int	is_range_sorted(t_stack *stk, int n_elem)
{
	int		i;
	int		lower;
	int		next;
	t_list	*lst;

	i = 1;
	lst = stk->top_node;
	lower = get_value_stk(lst);
	lst = lst->previous;
	while (i < n_elem)
	{
		next = get_value_stk(lst);
		if (next > lower)
			lower = next;
		else
			return (0);
		lst = lst->previous;
		i++;
	}
	return (1);
}

static int	has_ended(t_stack *stk_b)
{
	if (is_sorted(stk_b))
		return (1);
	if (is_inverse_sorted(stk_b))
		return (0);
	if (stk_b->n_elem == 3)
	{
		inverse_sort_3(stk_b);
		return (0);
	}
	return (-1);
}

static void	sort(t_stack *stk_a, t_stack *stk_b, t_list *lst, char ign_sorted)
{
	int	sorted;
	int	pushed_values;

	sorted = sort_half(stk_a, stk_b, lst);
	if (sorted)
		pushed_values = push_values_sorted(stk_b, stk_a, 0);
	else
		pushed_values = push_values_invsorted(stk_b, stk_a, 0);
	if (ign_sorted || (!ign_sorted && !is_sorted(stk_a)))
		rotate_elem(stk_a, pushed_values);
}

/*
 *	This will be a quick_sort with stacks.
 *	Returns if it is sorted normally (1)
 *	or invertally sorted (0)
 */
static int	sort_half(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	int		n_elem;
	t_list	*pivot;
	t_list	*tmp;
	int		end;

	end = has_ended(stk_b);
	if (end != -1)
		return (end);
	pivot = get_pivot(lst);
	n_elem = push_higher_values(stk_b, stk_a, pivot);
	tmp = pivot->next;
	pivot->next = NULL;
	tmp->previous = NULL;
	sort(stk_a, stk_b, lst, 1);
	if (is_range_sorted(stk_a, n_elem))
		rotate_elem(stk_a, n_elem);
	else
	{
		push_elem(stk_a, stk_b, n_elem);
		sort(stk_a, stk_b, tmp, 0);
	}
	ft_lstadd_back(&pivot, tmp);
	return (1);
}

/*
 *	Function used to sort n elements.
 */
void	sort_n(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	t_list	*pivot;
	t_list	*tmp;

	if (is_sorted(stk_a))
		return ;
	pivot = get_pivot(lst);
	push_higher_values(stk_a, stk_b, pivot);
	tmp = pivot->next;
	pivot->next = NULL;
	tmp->previous = NULL;
	sort(stk_a, stk_b, tmp, 1);
	ft_lstadd_back(&pivot, tmp);
	if (is_sorted(stk_a))
		return ;
	push_lower_values(stk_a, stk_b, pivot);
	if (get_bottom_value(stk_a) == get_value_lst(pivot))
		perform_reverse_rotate(stk_a);
	tmp = pivot->previous;
	tmp->next = NULL;
	pivot->previous = NULL;
	sort(stk_a, stk_b, lst, 1);
	while (get_top_value(stk_a) != get_lower_value(lst))
		perform_rotate(stk_a);
	ft_lstadd_back(&lst, pivot);
}
