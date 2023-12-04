
#include "push_swap.h"

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

/*
 *	Distributes the nodes of a linked list of pointers in two based if they are
 *	higher or lower from a pivot. If they are equal, an error is returned and
 *	everything is cleaned.
 */
static int	distribute_elem(t_list **first, t_list **second, t_list **pivot, t_list **lst)
{
	int		pivot_num;
	int		current_number;

	if (*lst == NULL || *pivot == NULL)
		return (0);
	pivot_num = get_node_number_from_lst(*pivot);
	while ((*lst)->next != NULL)
	{
		current_number = get_node_number_from_lst(*lst);
		if (current_number < pivot_num)
			ft_lstadd_back(first, extract_first(lst));
		else if (current_number > pivot_num)
			ft_lstadd_back(second, extract_first(lst));
		else
			return (clear_all(first, second, pivot, lst));
	}
	current_number = get_node_number_from_lst(*lst);
	if (current_number < pivot_num)
		ft_lstadd_back(first, extract_first(lst));
	else if (current_number > pivot_num)
		ft_lstadd_back(second, extract_first(lst));
	else
		return (clear_all(first, second, pivot, lst));
	return (0);
}

/*
 *	This method sorts the *lst from lesser to greater.
 *	Because lst is a list of pointers to nodes, sorting this list will have
 *	no effect on the elements of a stack it points to.
 *	We will also check if this list has repeated numbers, and will set
 *	*err as 1 if there are. It will also clean everything that used.
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
		return (clear_lsts(&second, &pivot));
	ft_lstadd_back(&first, pivot);
	if (second)
		second = quick_sort(second, err);
	if (*err)
		return (clear_lsts(&first, NULL));
	ft_lstadd_back(&first, second);
	return (first);
}
