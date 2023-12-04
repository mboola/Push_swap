
#include "push_swap.h"

void	push_swap(t_stack **stk_a, t_stack **stk_b, t_list **ptr_lst)
{
	if ((*stk_a)->n_elem > 5)
		sort_n(*stk_a, *stk_b, *ptr_lst);
	else if ((*stk_a)->n_elem == 5)
		sort_5(*stk_a, *stk_b);
	else if ((*stk_a)->n_elem == 4)
		sort_4(*stk_a, *stk_b);
	else if ((*stk_a)->n_elem == 3)
		sort_3(*stk_a);
	else if ((*stk_a)->n_elem == 2)
		sort_2(*stk_a);
	//if 1 already sorted
	clear_data(stk_a, stk_b, ptr_lst);
}
