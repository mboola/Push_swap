
#include "push_swap.h"

static int	clear_and_exit(t_stack **stk_a, t_stack **stk_b)
{
	clear_stack(stk_a);
	clear_stack(stk_b);
	//printf("Error\n");
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

static void	print_lst_reverse(t_list *lst)
{
	while (lst->previous != NULL)
	{
		printf("%d\n", *(int *)(lst->content));
		lst = lst->previous;
	}
	printf("%d\n", *(int *)(lst->content));
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

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_list	*ptr_to_nodes;
	int		err;

	err = 0;
	stk_a = create_stack('a', &err);
	stk_b = create_stack('b', &err);
	if (err)
	{
		printf("Error\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	push_argv_in_stack(argc, argv, stk_a, &err);
	if (err)
	{
		printf("Error\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	//to see if all goes as expected
	//print_lst(stk_a->bottom_node);
	//printf("n_elem: %d\n", (int)stk_a->n_elem);
	ptr_to_nodes = create_lst_ptr_to_nodes(stk_a, &err);		//this creates a t_list of pointers to elems of stack_a->nodes
	if (err)
	{
		printf("Error\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	ptr_to_nodes = quick_sort(ptr_to_nodes, &err);
	if (err)
	{
		printf("Error\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	//print_ptr_lst(ptr_to_nodes); //works
	//print_reverse(ptr_to_nodes); //works
	//print_lst(stk_a->bottom_node);
	//print_lst_reverse(stk_a->top_node);
	push_swap(&stk_a, &stk_b, &ptr_to_nodes);
	return (0);
}
