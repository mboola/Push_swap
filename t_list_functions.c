
#include "push_swap.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		*lst = (*lst)->next;
		ft_lstdelone(tmp, del);
		tmp = *lst;
	}
	ft_lstdelone(tmp, del);
	*lst = NULL;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*extract_last(t_list **lst)
{
	t_list	*new_last;
	t_list	*lst_iter;

	if (*lst == NULL)
		return (NULL);
	lst_iter = *lst;
	new_last = NULL;
	while (lst_iter->next != NULL)
	{
		new_last = lst_iter;
		lst_iter = lst_iter->next;
	}
	if (new_last != NULL)
		new_last->next = NULL;
	else
		*lst = NULL;
	return (lst_iter);
}

t_list	*extract_first(t_list **lst)
{
	t_list	*first;

	first = *lst;
	*lst = (*lst)->next;
	first->next = NULL;
	return (first);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

int		get_node_number_from_lst(t_list *ptr_lst)
{
	int	number;

	number = (*((t_node **)(ptr_lst->content)))->number;
	return (number);
}

int		ft_atoi(char *str, char **rest)
{
	int				num;
	int				n;

	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	*rest = str;
	num *= n;
	return (num);
}
