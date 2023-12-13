
#include "push_swap.h"

/*
 *	Function used to sort 4 elements.
 */
void	sort_4(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	//1-is sorted?
	//2-if lower on top, then push to stk B, sort stk A and then push back
	//3-

	//here the idea is getting the lower element or greater or whatever and
	//putting it in stack B, then sort stack A with sort_3 and then put back that element from
	//B to A again on top and move it on bottom if necessary.
	//WARNING: there are cases when this is not necessary and only a swap, rotate or reverse rotate
	//are necessary. check those cases and do whatever.
	if (stk_a->n_elem == stk_b->n_elem)
		return ;
}
