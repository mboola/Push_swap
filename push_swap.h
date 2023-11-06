/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:17:17 by mpovill-          #+#    #+#             */
/*   Updated: 2023/11/06 19:17:18 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef	struct	t_list
{
	int		*content;
	t_list	*next;
}	t_list;

typedef struct	t_stack
{
	//this will have a linked list of elements (ref to the first element of the list)
	t_list	*lst;
	//ref to the last elem of the list
	t_list	*last;
	//name of the stack: 'a' or 'b'
	char	name;
}	t_stack;

#endif
