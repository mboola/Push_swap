
#include "push_swap.h"

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
	//node->stack_name = 'a';
	lst = ft_lstnew(node);
	if (!lst)
	{
		*err = 1;
		free(node);
	}
	return (lst);
}

static t_list	*mat_to_node_lst(char **mat, int len, int *err)
{
	t_list	*node_lst;
	t_list	*node;
	int		i;
	int		num;

	i = 0;
	node_lst = NULL;
	while (i < len)
	{
		if (*(mat + i) == NULL || **(mat + i) == '\0')
		{
			*err = 1;
			return (clear_node_lst(&node_lst));
		}
		num = verify_number(*(mat + i), err);
		if (*err)
			return (clear_node_lst(&node_lst));
		node = create_node(num, err);
		if (*err)
			return(clear_node_lst(&node_lst));
		ft_lstadd_back(&node_lst, node);
		//*n_elem = *n_elem + 1;
		i++;
	}
	return (node_lst);
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

t_list	*convert_arg_to_lst(char **argv, int argc, int *err)
{
	char	**split;
	t_list	*lst;

	if (argc < 2)
	{
		*err = 1;
		return (NULL);
	}
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (*split == NULL)
		{
			*err = 1;
			free (split);
			return (NULL);
		}
		lst = mat_to_node_lst(split, matlen(split), err);
		matclear(&split);
	}
	else
		lst = mat_to_node_lst(argv + 1, argc - 1, err);
	return (lst);
}

//---------------------------------------------------------test

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