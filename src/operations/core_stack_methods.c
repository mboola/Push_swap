/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_stack_methods.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Puts an element at the top of the stack and updates 
 *	the top element and the number of elements of this stack.
 *	It also sets the name of the stack this node is in.
 *	WARNING: I don´t check NULLS because they are always checked outside.
 */
void	push_top(t_stack *stk, t_list *node)
{
	node->previous = stk->top_node;
	if (stk->n_elem == 0)
		stk->bottom_node = node;
	else
		stk->top_node->next = node;
	(stk->n_elem)++;
	stk->top_node = node;
	((t_node *)(node->content))->stack_name = stk->name;
}

/*
 *	Puts an element at the bottom of the stack and updates 
 *	the bottom element and the number of elements of this stack.
 *	It also sets the name of the stack this node is in.
 *	WARNING: I don´t check NULLS because they are always checked outside.
 */
void	push_bottom(t_stack *stk, t_list *node)
{
	node->next = stk->bottom_node;
	if (stk->n_elem == 0)
		stk->top_node = node;
	else
		stk->bottom_node->previous = node;
	(stk->n_elem)++;
	stk->bottom_node = node;
	((t_node *)(node->content))->stack_name = stk->name;
}

/*
 *	Gets the top element of the stack and updates the struct:
 *	Changes the number of elements, the pointer of top and also
 *	the pointer at the bottom if list ends up being NULL.
 */
t_list	*pop_top(t_stack *stk)
{
	t_list	*top_node;

	if (stk->n_elem == 0)
		return (NULL);
	top_node = stk->top_node;
	stk->top_node = stk->top_node->previous;
	(stk->n_elem)--;
	if (stk->n_elem == 0)
		stk->bottom_node = NULL;
	else
		stk->top_node->next = NULL;
	top_node->previous = NULL;
	top_node->next = NULL;
	return (top_node);
}

/*
 *	Gets the bottom element of the stack and updates the struct:
 *	Changes the number of elements, the pointer of bottom and also
 *	the pointer at the top if list ends up being NULL.
 */
t_list	*pop_bottom(t_stack *stk)
{
	t_list	*bottom_node;

	if (stk->n_elem == 0)
		return (NULL);
	bottom_node = stk->bottom_node;
	stk->bottom_node = stk->bottom_node->next;
	(stk->n_elem)--;
	if (stk->n_elem == 0)
		stk->top_node = NULL;
	else
		stk->bottom_node->previous = NULL;
	bottom_node->previous = NULL;
	bottom_node->next = NULL;
	return (bottom_node);
}
