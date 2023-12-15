
#include "push_swap.h"

static int	get_len_to_end(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int	get_len_to_start(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->previous != NULL)
	{
		lst = lst->previous;
		i++;
	}
	return (i);
}

static t_list	*get_pivot(t_list *lst, int size)
{
	int	i;
	int	len;

	i = 0;
	len = size / 2;
	while (i < len)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

/*
 *	This will separate the values greater than pivot to stack_b in the less movements possible.
 */
void	separate_first_values(t_stack *stk_origin, t_stack *stk_destination, t_list *pivot)
{
	int	count;
	
	count = get_len_to_end(pivot);
	while (count > 0)
	{
		if (get_top_value(stk_origin) > get_value_lst(pivot))
		{
			perform_push(stk_origin, stk_destination);
			count--;
		}
		else
			perform_rotate(stk_origin);
	}
}

void	separate_second_values(t_stack *stk_origin, t_stack *stk_destination, t_list *pivot)
{
	int	count;
	
	count = get_len_to_start(pivot);
	while (count > 0)
	{
		if (get_top_value(stk_origin) < get_value_lst(pivot))
		{
			perform_push(stk_origin, stk_destination);
			count--;
		}
		else
			perform_rotate(stk_origin);
	}
}

static void	print_stk(t_stack *stk)
{
	t_list	*top;

	top = stk->top_node;
	if (top == NULL)
		return ;
	while (top->previous != NULL)
	{
		printf("%d\n", *(int *)(top->content));
		top = top->previous;
	}
	printf("%d\n", *(int *)(top->content));
}

void	print_stacks(t_stack *stk_a, t_stack *stk_b, char *str)
{
	printf("Stack A %s:\n", str);
	print_stk(stk_a);
	printf("Stack B %s:\n", str);
	print_stk(stk_b);
}

//not used
void	return_values(t_stack *stk_origin, t_stack *stk_destination, t_list *pivot)
{
	while (stk_origin->n_elem > 0)
		perform_push(stk_origin, stk_destination);
	while (get_top_value(stk_destination) > get_value_lst(pivot))
		perform_rotate(stk_destination);
}

void	push_values_sorted(t_stack *stk_origin, t_stack *stk_destination, int n_elem)
{
	while (stk_origin->n_elem - n_elem > 1)
	{
		perform_reverse_rotate(stk_origin);
		perform_push(stk_origin, stk_destination);
	}
	perform_push(stk_origin, stk_destination);
}

void	push_values_inverse_sorted(t_stack *stk_origin, t_stack *stk_destination, int n_elem)
{
	while (stk_origin->n_elem - n_elem > 0)
		perform_push(stk_origin, stk_destination);
}

/*
 *	Here we push to stk_a all values lower than pivot and return the number of elements we pushed.
 */
int		push_lower(t_stack *stk_b, t_stack *stk_a, int pivot)
{
	int	pushed_elem;
	int	elem_to_push;

	elem_to_push = stk_b->n_elem / 2;
	pushed_elem = elem_to_push;
	while (elem_to_push > 0)
	{
		if (get_top_value(stk_b) < pivot)
		{
			perform_push(stk_b, stk_a);
			elem_to_push--;
		}
		else
			perform_rotate(stk_b);
	}
	return (pushed_elem);
}

/*
 *	This will be a quick_sort with stacks.
 *	Returns if it is sorted normally (1)
 *	or invertally sorted (0)
 */
int	sort_half(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	int		n_elem;
	int		len;
	t_list	*pivot;
	t_list	*tmp;
	int		sorted;
	int		i;

	if (is_sorted(stk_b))
		return (1);
	if (is_inverse_sorted(stk_b))
		return (0);

	//here it means it is not sorted
	if (stk_b->n_elem == 3)
	{
		//maybe check less movements if sorted reverse or sorted normally.
		if (sort_3_less_mov(stk_b))
		{
			sort_3(stk_b);
			return (1);
		}
		inverse_sort_3(stk_b);
		return (0);
	}
	else
	{
		len = get_len_to_start(lst);
		pivot = get_pivot(lst, len);

		//we put to stk_a all values lower than pivot.
		//n_elem is the number of elements pushed to stk a
		n_elem = push_lower(stk_b, stk_a, get_value_lst(pivot));

		//I get the list with the values to sort stk b has
		tmp = pivot->previous;
		pivot->previous = NULL;
		tmp->next = NULL;

		//I sort the values I have at stk b
		sorted = sort_half(stk_a, stk_b, pivot);

		//here I put above B the second part
		i = 0;
		while (i < n_elem)
		{
			perform_push(stk_a, stk_b);
			i++;
		}
		if (sorted)
			push_values_sorted(stk_a, stk_b, n_elem);
		else
			push_values_inverse_sorted(stk_a, stk_b, n_elem);

		//now I gotta sort the lower ones
		sorted = sort_half(stk_a, stk_b, lst);
		if (sorted)
			push_values_sorted(stk_a, stk_b, 0);
		else
			push_values_inverse_sorted(stk_a, stk_b, 0);
		ft_lstadd_back(&lst, pivot);
		return (1);
	}
}

/*
 *	Function used to sort n elements.
 */
void	sort_n(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	int		size;
	t_list	*pivot;
	t_list	*first;
	t_list	*second;

	if (is_sorted(stk_a))
		return ;
	size = get_len_to_end(lst);
	pivot = get_pivot(lst, size);

	printf("Pivot: %d\n", get_value_lst(pivot));
	print_stacks(stk_a, stk_b, "before separation");

	//pivot will always stay in the stack where we store the lowest values
	separate_first_values(stk_a, stk_b, pivot);

	//here we separate lst into: lst (with pivot), second
	second = pivot->next;
	pivot->next = NULL;
	second->previous = NULL;

	//this sorts b and puts all elements sorted back into a and moves them to the back of stack
	sort_half(stk_a, stk_b, second);

	if (is_sorted(stk_a))
	{
		ft_lstadd_back(&pivot, second);
		return ;
	}

	//this puts all values lower than pivot to stack b
	separate_second_values(stk_a, stk_b, pivot);

	//here we separate lst into: lst, pivot, second
	first = pivot->previous;
	first->next = NULL;
	pivot->previous = NULL;
	first = lst;

	sort_half(stk_a, stk_b, lst);

	//here all should be sorted
	ft_lstadd_back(&lst, pivot);
	ft_lstadd_back(&pivot, second);

	print_stacks(stk_a, stk_b, "Sorted");
}
