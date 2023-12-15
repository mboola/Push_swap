
#include "push_swap.h"


void	minor_sort(t_stack *stk)
{
	int	top_value;
	int	second_value;
	int	third_value;
	int	last_value;

	if (stk->n_elem <= 1)
		return ;
	top_value = get_value_stk(stk->top_node);
	second_value = get_value_stk(stk->top_node->previous);
	last_value = get_value_stk(stk->bottom_node);
	if (top_value > second_value)
		return ;
	if (top_value < second_value && top_value > last_value)
			perform_swap(stk);
	if (stk->n_elem <= 3)
	{
		if (top_value < second_value && top_value <= last_value)
			perform_rotate(stk);
		return ;
	}
	third_value = get_value_stk(stk->top_node->previous->previous);
	if (top_value > last_value)
		perform_rotate(stk);
	else
	{
		//TODO: not sure if this or only a rotate
		perform_rotate(stk);
	}
}

/*
 *	Function used to sort n elements.
 */
void	sort_n(t_stack *stk_a, t_stack *stk_b, t_list *lst)
{
	t_list	*curr_value;
	t_list	*highest;

	//if it is already sorted we do nothing
	if (is_sorted(stk_a))
		return ;
	curr_value = ft_lstlast(lst);
	//printf("%d", get_value_lst(curr_value));
	highest = curr_value;

	//first we put the highest number on top of stack a
	if (find_shortest_path(stk_a, curr_value))
	{
		while (get_top_value(stk_a) != get_value_lst(curr_value))
		{
			perform_push(stk_a, stk_b);

			//mabe do this two togheter
			minor_sort(stk_b);
			perform_reverse_rotate(stk_a);
		}
	}
	else
	{
		while (get_top_value(stk_a) != get_value_lst(curr_value))
		{
			perform_push(stk_a, stk_b);
			minor_sort(stk_b);
		}
	}

	curr_value = curr_value->previous;
	//here ive got biggest elemen on top of A and B more or less sorted
	while (stk_b->n_elem != 0 || !is_sorted(stk_a))
	{
		if (get_stk_lst(curr_value) == 'a')
		{
			if (find_shortest_path(stk_a, curr_value))
			{
				perform_reverse_rotate(stk_a);
				while (get_top_value(stk_a) != get_value_lst(curr_value))
				{
					perform_push(stk_a, stk_b);
					minor_sort(stk_b);
					perform_reverse_rotate(stk_a);
				}
			}
			else
			{
				//here we first rotate till last elem is on top
				while (get_top_value(stk_a) != get_value_lst(highest))
					perform_rotate(stk_a);
				perform_rotate(stk_a);
				//then we rotate and push b
				while (get_top_value(stk_a) != get_value_lst(curr_value))
				{
					perform_push(stk_a, stk_b);
					minor_sort(stk_b);
				}
				perform_push(stk_a, stk_b);
				while (get_top_value(stk_a) != get_value_lst(curr_value->next))
					perform_reverse_rotate(stk_a);
				perform_push(stk_b, stk_a);
			}
		}
		//value is in stack B
		else
		{
			if (find_shortest_path(stk_b, curr_value))
			{
				while (get_top_value(stk_b) != get_value_lst(curr_value))
					perform_reverse_rotate(stk_b);
				perform_push(stk_b, stk_a);
			}
			else
			{
				while (get_top_value(stk_b) != get_value_lst(curr_value))
					perform_rotate(stk_b);
				perform_push(stk_b, stk_a);
			}
		}
		curr_value = curr_value->previous;
	}
	
}
