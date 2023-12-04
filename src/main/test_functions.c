
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	int		err;

	err = 0;
	stk_a = create_stack('a', &err);
	if (err)
	{
		printf("Error with creation?!!wtf\n");
		return (0);
	}
	push_argv_in_stack(argc, argv, stk_a, &err);
	if (err)
	{
		printf("Arguments not correct wtf\n");
		clear_stack(&stk_a);
		return (0);
	}
	printf("n_elem: %d\n", (int)stk_a->n_elem);
	clear_stack(&stk_a);
	return (0);
}
