
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
		printf("Error with creation?!!wtf\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	push_argv_in_stack(argc, argv, stk_a, &err);
	if (err)
	{
		printf("Arguments not correct.\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	//to see if all goes as expected
	print_lst(stk_a->bottom_node);
	printf("n_elem: %d\n", (int)stk_a->n_elem);

	ptr_to_nodes = create_lst_ptr_to_nodes(stk_a, &err);		//this creates a t_list of pointers to elems of stack_a->nodes
	if (err)
	{
		printf("Error creating list of pointers.\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	ptr_to_nodes = quick_sort(ptr_to_nodes, &err);
	if (err)
	{
		printf("Error repeated number as input\n");
		return (clear_and_exit(&stk_a, &stk_b));
	}
	clear_data(&stk_a, &stk_b, &ptr_to_nodes);
	return (0);
}
