
#include "push_swap.h"

int		get_value_lst(t_list *ptr_lst)
{
	int	number;

	number = (*((t_node **)(ptr_lst->content)))->number;
	return (number);
}

int		get_higher_value(t_list *lst)
{
	return (get_value_lst(ft_lstlast(lst)));
}

int		get_lower_value(t_list *lst)
{
	return (get_value_lst(lst));
}

/*
 *	Creates a linked list of pointers to nodes of a stack.
 */
t_list	*create_lst_ptr_to_nodes(t_stack *stk, int *err)
{
	t_list	*ptr_lst;
	t_list	*ptr_node;
	t_list	*nodes;

	ptr_lst = NULL;
	nodes = stk->bottom_node;
	while(nodes->next != NULL)
	{
		// IMPORTANT: here I only malloc the mem of the new node of t_list.
		// The content of this node will be a the memory address of the content of our t_list nodes.
		// This memory address will store a pointer t_node with a number and a stack.
		ptr_node = ft_lstnew(&(nodes->content));	//nodes->content is the (num, stack)
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
