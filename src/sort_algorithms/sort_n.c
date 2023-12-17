
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
 *	Here we push values higher than pivot to stack B.
 */
int	push_higher_values(t_stack *stk_origin, t_stack *stk_destination, t_list *pivot)
{
	int	n_elem;
	int	i;

	//we get the number of elements from pivot to end
	n_elem = get_len_to_end(pivot);
	i = n_elem;
	while (n_elem > 0)
	{
		if (get_top_value(stk_origin) > get_value_lst(pivot))
		{
			perform_push(stk_origin, stk_destination);
			n_elem--;
		}
		else
			perform_rotate(stk_origin);
	}
	return (i);
}

void	push_lower_values(t_stack *stk_origin, t_stack *stk_destination, t_list *pivot)
{
	int	n_elem;

	n_elem = get_len_to_start(pivot);
	while (n_elem > 0)
	{
		if (get_top_value(stk_origin) < get_value_lst(pivot))
		{
			perform_push(stk_origin, stk_destination);
			n_elem--;
		}
		else
			perform_rotate(stk_origin);
	}
}

/*
 *	This will separate the values greater than pivot to stack_b in the less movements possible.
 */
int	separate_first_values(t_stack *stk_origin, t_stack *stk_destination, t_list *pivot)
{
	int	count;
	int	i;
	
	count = get_len_to_end(pivot);
	i = count;
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
	return (i);
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

static void	print_lst(t_list *lst)
{
	while (lst->next != NULL)
	{
		printf("%d\n", *(int *)(lst->content));
		lst = lst->next;
	}
	printf("%d\n", *(int *)(lst->content));
}

void	print_stacks(t_stack *stk_a, t_stack *stk_b, char *str)
{
	printf("Stack A %s:\n", str);
	print_stk(stk_a);
	printf("Stack B %s:\n", str);
	print_stk(stk_b);
}

int	push_values_sorted(t_stack *stk_origin, t_stack *stk_destination, int n_elem)
{
	int	i;

	i = 0;
	if (stk_origin->n_elem == 0)
		return (0);
	while (stk_origin->n_elem - n_elem > 1)
	{
		perform_reverse_rotate(stk_origin);
		perform_push(stk_origin, stk_destination);
		i++;
	}
	i++;
	perform_push(stk_origin, stk_destination);
	return (i);
}

int	push_values_inverse_sorted(t_stack *stk_origin, t_stack *stk_destination, int n_elem)
{
	int	i;

	i = 0;
	while (stk_origin->n_elem - n_elem > 0)
	{
		perform_push(stk_origin, stk_destination);
		i++;
	}
	return (i);
}

void	rotate_elem(t_stack *stk, int n_elem)
{
	int	i;

	i = 0;
	while (i < n_elem)
	{
		perform_rotate(stk);
		i++;
	}
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
	int pushed_values;

	// is this stack already sorted?
	if (is_sorted(stk_b))
		return (1);
	if (is_inverse_sorted(stk_b))
		return (0);
	
	//if it is not sorted, we look if it can inmediatebly be sorted
	if (stk_b->n_elem == 3)
	{
		//and we sort it with the less movements possible
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
		//if it is not sorted and has more than 3 elements
		//we will separate this stack with a pivot
		len = get_len_to_end(lst);
		pivot = get_pivot(lst, len);

		//we put to stk_a all values higher than pivot.
		//n_elem is the number of elements pushed to stk a
		n_elem = push_higher_values(stk_b, stk_a, pivot);

		//I get the list with the values to sort stk b has
		tmp = pivot->next;
		pivot->next = NULL;
		tmp->previous = NULL;

		//I sort the values I have at stk b
		sorted = sort_half(stk_a, stk_b, lst);

		if (sorted)
			pushed_values = push_values_sorted(stk_b, stk_a, 0);
		else
			pushed_values = push_values_inverse_sorted(stk_b, stk_a, 0);
		
		rotate_elem(stk_a, pushed_values);

		// TODO: is the next range sorted? (pivot to end) (n_elem)
		//if it is
			//rotate_elem(stk_a, n_elem);
		//else
			//push n_elem to stk b and sort them
			//sorted = sort_half(stk_a, stk_b, pivot);

		int i = 0;
		while (i < n_elem)
		{
			perform_push(stk_a, stk_b);
			i++;
		}

		sorted = sort_half(stk_a, stk_b, tmp);
		
		if (sorted)
			pushed_values = push_values_sorted(stk_b, stk_a, 0);
		else
			pushed_values = push_values_inverse_sorted(stk_b, stk_a, 0);

		//and rotate them if not sorted
		if (!is_sorted(stk_a))
			rotate_elem(stk_a, pushed_values);

		//here everything should be sorted
		ft_lstadd_back(&tmp, pivot);
		return (1);
	}
}

/*
 *	Function used to sort n elements.
	--pretty sure this works as expected
 */
void	sort_n(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	int		size;
	t_list	*pivot;
	t_list	*first;
	t_list	*second;
	int		pushed_values;

	//if sorted we end
	if (is_sorted(stk_a))
		return ;

	//total size of the list
	size = get_len_to_end(lst);

	//pivot will be the node size/2
	pivot = get_pivot(lst, size);

	//printf("Pivot: %d\n", get_value_lst(pivot));
	//print_stacks(stk_a, stk_b, "before separation");

		//--pivot will always stay in the stack where we store the lowest values

	//we push values higher than pivot to stack B to sort them recursively
	int n_elem = push_higher_values(stk_a, stk_b, pivot);

	//print_stacks(stk_a, stk_b, "after separation");

	//here we separate lst into: first part of lst (with pivot), and second
	second = pivot->next;
	pivot->next = NULL;
	second->previous = NULL;

	//and we sort the elements in stack b
	int sorted = sort_half(stk_a, stk_b, second);

	//we put all those elements back at stack a, the higher ones at the bottom and the big ones on top
	if (sorted)
		pushed_values = push_values_sorted(stk_b, stk_a, 0);
	else
		pushed_values = push_values_inverse_sorted(stk_b, stk_a, 0);

	//and we put the lower elements on top
	rotate_elem(stk_a, pushed_values);

	//here I put back lst and second
	ft_lstadd_back(&pivot, second);

	//if it is 'magically' sorted we end
	if (is_sorted(stk_a))
	{
		//print_stacks(stk_a, stk_b, "Sorted");
		return ;
	}

	//and now we push the lower values to stack b. I should do it till i find the first sorted element.
	//I should store the pivot at the back.
	push_lower_values(stk_a, stk_b, pivot);

	//And here I retrieve the pivot
	if (get_bottom_value(stk_a) == get_value_lst(pivot))
		perform_reverse_rotate(stk_a);

	//here I separate lst into: lst, second (with pivot)
	first = pivot->previous;
	first->next = NULL;
	pivot->previous = NULL;

	//and we sort the elements in stack b
	sorted = sort_half(stk_a, stk_b, lst);

	//we put all those elements back at stack a, the higher ones at the bottom and the big ones on top
	if (sorted)
		pushed_values = push_values_sorted(stk_b, stk_a, 0);
	else
		pushed_values = push_values_inverse_sorted(stk_b, stk_a, 0);

	//and we put the lower elements on top
	rotate_elem(stk_a, pushed_values);

	while (get_top_value(stk_a) != get_lower_value(lst))
		perform_rotate(stk_a);

	//here I put back lst and second
	ft_lstadd_back(&lst, pivot);

	//here all should be sorted
	//print_stacks(stk_a, stk_b, "Sorted");
}
