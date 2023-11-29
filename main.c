
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
	clear_data(&stk_a, &stk_b, NULL);
	//ptr_lst	= get_ptr_lst(stk_a, &err);
	//if (err)
	//	return (clear_and_exit(&stk_a, &stk_b));
	//print_lst(ptr_lst);
	//clear_data(&stk_a, &stk_b, &ptr_lst);
	/*
	ptr_lst = sort_ptr_lst(&ptr_lst, &err);
	if (err)
		return (clear_and_exit(&stk_a, &stk_b));
	push_swap(&stk_a, &stk_b, &ptr_lst);
	*/
	return (0);
}