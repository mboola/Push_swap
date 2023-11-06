/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:17:17 by mpovill-          #+#    #+#             */
/*   Updated: 2023/11/06 19:17:18 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	*get_input(int argc, char **argv, int *len, int *err)
{
	//here I get the length of the array to create someway.

	//then I insert the elem comparing all of them with num
}

static int	create_stacks(t_stack *a, t_stack *b)
{
	int	err;

	err = 0;
	b = create_t_stack('b', &err);
	if (err)
		return(err);
	a = create_t_stack('a', &err);
	if (err)
	{
		free(b);
		return(err);
	}
	return (1);
}

static int	check_convert_input(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	err;
	int len;
	int	*arr;

	err = 0;
	//check input correct
	arr = get_input(argc, argv, &len, &err);
	if (err)
		return (err);
	err = create_stacks(a, b);
	if (err)
	{
		free(arr);
		return (err);
	}
	//put elements in a
	put_elements(a, arr, len, &err);
	return (0);
}

int main(int argc, char **argv)
{
	int		err;
	t_stack	*stack_a;
	t_stack	*stack_b;

	err = check_convert_input(argc, argv, stack_a, stack_b);
	if (err)
	{
		//display error
		return (0);
	}
	//sort
	return (0);
}