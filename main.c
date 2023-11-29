
#include "push_swap.h"

static int	clear_and_exit(t_stack **stk_a, t_stack **stk_b)
{
	clear_stack(stk_a);
	clear_stack(stk_b);
	printf("Error with mem allocation\n.");
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
	stk_a->nodes = convert_arg_to_lst(argv, argc, &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	print_lst(stk_a->nodes);
	ptr_lst	= get_ptr_lst(stk_a, &err);		//this creates a t_list of pointers to elems of stack_a->nodes
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	print_ptr_lst(ptr_lst);

	//t_list	*test = extract_last(ptr_lst);
	//t_list	*test = extract_first(&ptr_lst);
	//printf("element:\n");
	//print_ptr_lst(test);
	//printf("rest of the list:\n");
	//print_ptr_lst(ptr_lst);

	/*
	//test
	t_list	*node1 = ft_lstlast(ptr_lst);
	ptr_lst->next = NULL;
	node1->next = ptr_lst;
	ptr_lst = node1;
	printf("List swaped:\n");
	print_ptr_lst(ptr_lst);
	printf("Stack: \n");
	print_lst(stk_a->nodes);

	//printf("Number: %d\n", get_node_number_from_lst(ptr_lst));
	//ftest*/

	
	ptr_lst = sort_ptr_lst(ptr_lst, &err);
	//ptr_lst = quick_sort(ptr_lst, &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	if (ptr_lst)
		print_ptr_lst(ptr_lst);
	clear_data(&stk_a, &stk_b, &ptr_lst);


	//push_swap(&stk_a, &stk_b, &ptr_lst);
	return (0);
}