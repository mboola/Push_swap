
#include "push_swap.h"

void	free_node(void *content)
{
	t_node	*node;

	node = (t_node *)content;
	free(node);
}

void	free_ptr_node(void *content)
{
}

t_list	*clear_ptr_lst(t_list **lst)
{
	ft_lstclear(lst, free_ptr_node);
	return (NULL);
}

t_list	*clear_node_lst(t_list **lst)
{
	ft_lstclear(lst, free_node);
	return (NULL);
}

void	clear_stack(t_stack **stk)
{
	clear_node_lst(&((*stk)->nodes));
	free(*stk);
}

void	clear_data(t_stack **stk_a, t_stack **stk_b, t_list	**ptr_lst)
{
	clear_stack(stk_a);
	clear_stack(stk_b);
	clear_ptr_lst(ptr_lst);
}
