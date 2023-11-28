
#include "push_swap.h"

t_list	*get_ptr_lst(t_stack *stk, int *err)
{
	t_list	*ptr_lst;
	t_list	*ptr_node;
	t_list	*nodes;

	ptr_lst = NULL;
	nodes = stk->nodes;
	while(nodes->next != NULL)
	{
		ptr_node = ft_lstnew(nodes->content);	//nodes->content is the (num, stack)
		if (!ptr_node)
		{
			*err = 1;
			return (clear_ptr_lst(&ptr_lst));
		}
		ft_lstadd_back(&ptr_lst, ptr_node);
		nodes = nodes->next;
	}
	ptr_node = ft_lstnew(nodes->content);
	if (!ptr_node)
	{
		*err = 1;
		return (clear_ptr_lst(&ptr_lst));
	}
	ft_lstadd_back(&ptr_lst, ptr_node);
	return (ptr_lst);
}

t_list	*sort_ptr_lst(t_list **lst, int *err)
{
	t_list	*sorted_lst;

	clear_ptr_lst(lst);
	return (sorted_lst);
}
