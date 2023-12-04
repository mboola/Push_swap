
#include "push_swap.h"

/*
 *	Function used to sort 5 elements.
 */
void	sort_5(t_stack *stk_a, t_stack *stk_b)
{
	//here the idea is getting the lower element or greater or whatever and
	//putting it in stack B, then sort stack A with sort_3 and then put back that element from
	//B to A again on top and move it on bottom if necessary.
	//WARNING: there are cases when this is not necessary and only a swap, rotate or reverse rotate
	//are necessary. check those cases and do whatever.
	if (stk_a->n_elem == stk_b->n_elem)
		return ;
}
