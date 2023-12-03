
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
	//here I must check correct input:
		// ./push_swap ""
		// ./push_swap "" ""
		// ./push_swap "" "" ""
		// ./push_swap 
		// ./push_swap "123 1 " ""
		// ./push_swap "1" "2" "3" ??????!!!! TODO
	//write(1, "b\n", 2);	//arribes
	printf("%d\n", argc);
	stk_a->nodes = convert_arg_to_lst(argv, argc, &err);
	if (err)
	{
		write(1, "a\n", 2); //here it doesnt
		return (clear_and_exit(&stk_a, &stk_b));
	}
	write(1, "c\n", 2);
	print_lst(stk_a->nodes);
	print_len_lst(stk_a->nodes);
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
	//return (0);
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