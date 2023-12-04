
#include "push_swap.h"

t_list	*create_ptr_lst(t_stack *stk, int *err)
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

static int	clear_all(t_list **first, t_list **second, t_list **pivot, t_list **lst)
{
	if (first && *first)
		clear_ptr_lst(first);
	if (second && *second)
		clear_ptr_lst(second);
	if (pivot && *pivot)
		clear_ptr_lst(pivot);
	if (lst && *lst)
		clear_ptr_lst(lst);
	return (1);
}

static t_list	*clear_lsts(t_list **lst, t_list **pivot)
{
	clear_all(lst, pivot, NULL, NULL);
	return (NULL);
}

static int	distribute_elem(t_list **first, t_list **second, t_list **pivot, t_list **lst)
{
	int		pivot_num;
	int		current_number;

	if (*lst == NULL || *pivot == NULL)		// If there is no list to sort, we leave
		return (0);
	pivot_num = get_node_number_from_lst(*pivot);
	while ((*lst)->next != NULL)
	{
		current_number = get_node_number_from_lst(*lst);
		if (current_number < pivot_num)
			ft_lstadd_back(first, extract_first(lst));
		else if (current_number > pivot_num)
			ft_lstadd_back(second, extract_first(lst));
		else	// current_number == pivot_num
			return (clear_all(first, second, pivot, lst));
	}
	current_number = get_node_number_from_lst(*lst);
	if (current_number < pivot_num)
		ft_lstadd_back(first, extract_first(lst));
	else if (current_number > pivot_num)
		ft_lstadd_back(second, extract_first(lst));
	else	// current_number == pivot_num
		return (clear_all(first, second, pivot, lst));
	return (0);
}

/*
 *	*lst is a linked list of pointers to t_node of another t_list.
 *	*sorted list will be the same list (w/o freeing anything) but sorted
 *	!!!!!!here we won't malloc or free anything, we will just sort things!!!!!!!!
*/

t_list	*quick_sort(t_list *lst, int *err)
{
	t_list	*first;			// The first list of numbers (lower of pivot)
	t_list	*second;		// The second list of numbers (higher of pivot)
	t_list	*pivot;			// Last elem of list acting as a pivot

	first = NULL;
	second = NULL;
	pivot = extract_last(&lst);
	if (distribute_elem(&first, &second, &pivot, &lst))
	{
		*err = 1;
		return (NULL);
	}
	if (first)
		first = quick_sort(first, err);
	if (*err)
		return (clear_lsts(&second, &pivot));	//TODO: here I must clear pivot and second list
	ft_lstadd_back(&first, pivot);
	if (second)
		second = quick_sort(second, err);
	if (*err)
		return (clear_lsts(&first, NULL));	//TODO: here I must clear first list
	ft_lstadd_back(&first, second);
	return (first);
}
