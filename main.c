
#include "push_swap.h"

static int	clear_and_exit(t_stack **stk_a, t_stack **stk_b)
{
	clear_stack(stk_a);
	clear_stack(stk_b);
	printf("Error\n");
	return (0);
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

static void	print_ptr_lst(t_list *lst)
{
	t_node	**node;

	while (lst->next != NULL)
	{
		node = (t_node **)(lst->content);
		printf("%d\n", (*node)->number);
		lst = lst->next;
	}
	node = (t_node **)(lst->content);
	printf("%d\n", (*node)->number);
}

static void	print_len_lst(t_list *lst)
{
	size_t	size;

	if (lst == NULL)
	{
		printf("Len: 0");
		return ;
	}
	size = 1;
	while (lst->next != NULL)
	{
		size++;
		lst = lst->next;
	}
	printf("Len: %d\n", (int)size);
}

static void	print_reverse(t_list *lst)
{
	t_list *last;
	t_node	**node;

	printf("starting to print reverse:\n");
	last = ft_lstlast(lst);
	while (last->previous != NULL)
	{
		node = (t_node **)(last->content);
		printf("%d\n", (*node)->number);
		last = last->previous;
	}
	node = (t_node **)(last->content);
	printf("%d\n", (*node)->number);
}

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_list	*ptr_lst;
	int		err;

	err = 0;
	stk_a = create_stack('a', &err);
	stk_b = create_stack('b', &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	stk_a->nodes = convert_arg_to_lst(argv, argc, &(stk_a->n_elem), &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	printf("n_elem: %d\n", (int)stk_a->n_elem);
	print_lst(stk_a->nodes);
	print_len_lst(stk_a->nodes);
	ptr_lst	= get_ptr_lst(stk_a, &err);		//this creates a t_list of pointers to elems of stack_a->nodes
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	//print_ptr_lst(ptr_lst);
	ptr_lst = quick_sort(ptr_lst, &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	
	if (ptr_lst)
	{
		print_ptr_lst(ptr_lst);
		print_reverse(ptr_lst);
	}
	push_swap(&stk_a, &stk_b, &ptr_lst);
	return (0);
}