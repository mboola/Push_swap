
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


t_list	*quick_sort(t_list *lst, int *err)
{
	/*
	t_list	*first;			// The first list of numbers (lower of pivot)
	t_list	*second;		// The second list of numbers (higher of pivot)
	t_list	*node;			// A new node of the t_list
	int		pivot;

	// If something fails here, it gets cleared. (Except lst)
	sort_elem(lst, &first, &second, err);
	if (*err)
		return (NULL);
	first = rearrange_list(&first, err);
	if (*err)
		return (clear_lists(&second, NULL));
	pivot = *(int *)(ft_lstlast(lst)->content);	// We get the last element
	node = create_node(pivot, err);	// we create a node with the pivot
	if (*err)
		return (clear_lists(&first, &second));
	ft_lstadd_back(&first, node);
	second = rearrange_list(&second, err);
	if (*err)
		return (clear_lists(&first, NULL));
	ft_lstadd_back(&first, second);*/
	//return (first);
	return (NULL);
}

/*
 *	*lst has all nodes. We will take them out of lst and put them in first or second
*/
void	sort_elems(t_list *lst, t_list **first, t_list **second)
{
	/*
	int		pivot;			// The pivot to sort elems
	int		current_number;	// The current number to sort
	t_list	*node;			// A new node of the t_list

	*first = NULL;
	*second = NULL;*/
}

/*
 *	*lst is a linked list of pointers to t_node of another t_list.
 *	*sorted list will be the same list (w/o freeing anything) but sorted
 *	!!!!!!here we won't malloc or free anything, we will just sort things!!!!!!!!
*/
t_list	*sort_ptr_lst(t_list *lst, int *err)
{
	/*
	t_list	*first;			// The first list of numbers (lower of pivot)
	t_list	*second;		// The second list of numbers (higher of pivot)
	t_list	*pivot;			// A new node of the t_list
	int		pivot;

	//sorted_lst = NULL;
	//sort_elem(lst, &first, &second);


	//clear_ptr_lst(lst);*/
	return (NULL);
}
