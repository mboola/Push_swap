
#include "push_swap.h"

//MUST also verify it is not max int
static int		verify_number(char *str, int *err)
{
	int		num;
	char	*rest;

	num = ft_atoi(str, &rest);
	if (*rest != '\0')
		*err = 1;
	return (num);
}

static t_list	*create_node(int number, int *err)
{
	t_list	*lst;
	t_node	*node;

	node = malloc (sizeof(t_node));
	if (!node)
	{
		*err = 1;
		return (NULL);
	}
	node->number = number;
	lst = ft_lstnew(node);
	if (!lst)
	{
		*err = 1;
		free(node);
	}
	return (lst);
}

static void	matclear(char ***mat)
{
	size_t	i;
	char	**tmp;

	tmp = *mat;
	i = 0;
	while (*(tmp + i) != NULL)
	{
		free(*(tmp + i));
		i++;
	}
	free(*mat);
}

static size_t	matlen(char **mat)
{
	size_t	i;

	i = 0;
	while (*(mat + i) != NULL)
		i++;
	return (i);
}

static void	conv_and_push_elems(char **mat, int len, t_stack *stk, int *err)
{
	t_list	*node;
	int		i;
	int		num;

	i = 0;
	while (i < len)
	{
		if (*(mat + i) == NULL || **(mat + i) == '\0')
		{
			*err = 1;
			return ;
		}
		num = verify_number(*(mat + i), err);
		if (*err)
			return ;
		node = create_node(num, err);
		if (*err)
			return ;
		push_top(stk, node);
		i++;
	}
}

void	push_argv_in_stack(int argc, char **argv, t_stack *stk, int *err)
{
	char	**split;

	if (argc < 2)
		*err = 1;
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (split == NULL)
			*err = 1;
		else if (*split == NULL)
		{
			*err = 1;
			free (split);
		}
		else
		{
			conv_and_push_elems(split, matlen(split), stk, err);
			matclear(&split);
		}
	}
	else
		conv_and_push_elems(argv + 1, argc - 1, stk, err);
}
