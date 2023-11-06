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

//here arr will have at least one elem
void	put_elements(t_stack stk, int *arr, int len, int *err)
{
	int		i;
	t_list	*node;

	i = 1;
	node = ft_create_node(arr[0], err);
	while (i < len && !*err)
	{
		//add node to the back of the lst
		//....		here		...

		//create a new node with the next elem of the arr
		node = ft_create_node(arr[i], err);
		i++;
	}
	//add node to the back of the lst
	//....		here		...

	//set also as the last elem of the list
}

t_stack	*create_t_stack(char name, int *err)
{
	t_stack	*stack = malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		*err = -1;
		return (NULL);
	}
	stack->name = name;
	stack->*lst = NULL;
	stack->*last = NULL;
	return (stack);
}
