
#include "push_swap.h"

/*
 *	Puts an element at the top of the stack and updates 
 *	the top element and the number of elements of this stack.
 *	It also sets the stack this node is in.
 *	WARNING: I don´t check NULLS because they are always checked outside.
 */
void	push(t_stack *stk, t_list *node)
{
	node->previous = stk->top_node;
	if (stk->top_node != NULL)
		stk->top_node->next = node;
	(stk->n_elem)++;
	stk->top_node = node;
	//this is exclusive of push_swap, not of this struct
	(t_node *)(node->content)->stack_name = stk->name;
}

/*
 *	Gets the top element of the stack and updates the struct:
 *	Changes the number of elements, the pointer of top and also
 *	the pointer of the bottom one if list ends up being NULL.
 */
t_list	*pop(t_stack *stk)
{
	t_list	*top_node;

	if (stk->n_elem == 0)
		return (NULL);
	top_node = stk->top_node;
	stk->top_node = stk->top_node->previous;
	(stk->n_elem)--;
	if (stk->n_elem == 0)
		stk->bottom_node = NULL;
	top_node->previous = NULL;
	top_node->next = NULL; //technically not necessary
	return (top_node);
}