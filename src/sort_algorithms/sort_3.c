
#include "push_swap.h"

static void	init_values(int *t_val, int *b_val, int *m_val, t_stack *stk)
{
	*t_val = get_top_value(stk);
	*b_val = get_bottom_value(stk);
	*m_val = get_value_stk(stk->bottom_node->next);
}

/*
 *	Function used to sort 3 elements.
 */
void	sort_3(t_stack *stk)
{
	int	top_value;
	int	bottom_value;
	int	middle_value;

	init_values(&top_value, &bottom_value, &middle_value, stk);
	if (top_value < middle_value)
	{
		if (top_value < bottom_value)
		{
			if (middle_value > bottom_value)
			{
				perform_swap(stk);
				perform_rotate(stk);
			}
		}
		else
			perform_reverse_rotate(stk);
	}
	else
	{
		if (top_value < bottom_value)
			perform_swap(stk);
		else
		{
			if (middle_value > bottom_value)
			{
				perform_swap(stk);
				perform_reverse_rotate(stk);
			}
			else
				perform_rotate(stk);
		}
	}
}

void	inverse_sort_3(t_stack *stk)
{
	int	top_value;
	int	bottom_value;
	int	middle_value;

	init_values(&top_value, &bottom_value, &middle_value, stk);
	if (top_value > middle_value)
	{
		if (top_value > bottom_value)
		{
			if (middle_value < bottom_value)
			{
				perform_swap(stk);
				perform_rotate(stk);
			}
		}
		else
			perform_reverse_rotate(stk);
	}
	else
	{
		if (top_value > bottom_value)
			perform_swap(stk);
		else
		{
			if (middle_value < bottom_value)
			{
				perform_swap(stk);
				perform_reverse_rotate(stk);
			}
			else
				perform_rotate(stk);
		}
	}
}

static int	sort_3_mov(t_stack *stk)
{
	int	top_value;
	int	bottom_value;
	int	middle_value;

	init_values(&top_value, &bottom_value, &middle_value, stk);
	if (top_value < middle_value)
	{
		if (top_value < bottom_value)
		{
			if (middle_value > bottom_value)
				return (2);
		}
		else
			return (1);
	}
	else if (top_value < bottom_value)
		return (1);
	else if (middle_value > bottom_value)
		return (2);
	else
		return (1);
	return (0);
}

static int	inv_sort_3_mov(t_stack *stk)
{
	int	top_value;
	int	bottom_value;
	int	middle_value;

	init_values(&top_value, &bottom_value, &middle_value, stk);
	if (top_value > middle_value)
	{
		if (top_value > bottom_value)
		{
			if (middle_value < bottom_value)
				return (2);
		}
		else
			return (1);
	}
	else if (top_value > bottom_value)
		return (1);
	else if (middle_value < bottom_value)
		return (2);
	else
		return (1);
	return (0);
}

int	sort_3_less_mov(t_stack *stk)
{
	int	n_sort;
	int	n_inv_sort;

	n_sort = sort_3_mov(stk);
	n_inv_sort = inv_sort_3_mov(stk);

	if (n_sort < n_inv_sort)
		return (1);
	return (0);
}
