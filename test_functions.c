
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	int		err;

	err = 0;
	stk_a = create_stack('a', &err);
	if (err)
	{
		printf("Error with creation???!!wtf\n");
		return (0);
	}
	push_argv_in_stack(argc, argv, stack_a, &err);
	if (err)
	{
		printf("Error with creation???!!wtf\n");
		clear_stack(stk_a);
		return (0);
	}
	return (0);
}