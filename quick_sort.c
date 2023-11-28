
#include "quick_sort.h"

t_list	*get_ptr_lst(t_stack *stk, int *err)
{
	t_list	*ptr_lst;
	t_list	*ptr_node;
	t_list	*nodes;

	ptr_lst = NULL;
	nodes = stk->nodes;
	while(nodes->next != NULL)
	{
		ptr_node = ft_lstnew(nodes->content);	//nodes->content is the (num, stack)
		if (!ptr_node)
		{
			*err = 1;
			return (clear_ptr_lst(&ptr_lst));
		}
		ft_lstadd_back(&ptr_lst, ptr_node);
		nodes = nodes->next;
	}
	ptr_node = ft_lstnew(nodes->content);
	if (!ptr_node)
	{
		*err = 1;
		return (clear_ptr_lst(&ptr_lst));
	}
	ft_lstadd_back(&ptr_lst, ptr_node);
	return (ptr_lst);
}

t_list	*sort_ptr_lst(t_list **lst, int *err)
{
	t_list	*sorted_lst;

	clear_ptr_lst(lst);
	return (sorted_lst);
}



t_list	*rearrange_list(t_list **lst, int *err);

void	free_node(void *content)
{
	free(content);
}

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

/*
If malloc fails it sets err as one. If not it creates a node of t_list
and sets num as the content of that node.
*/
t_list	*create_node(int num, int *err)
{
	int		*n;
	t_list	*node;

	n = malloc(sizeof(int));
	if (!n)
	{
		*err = 1;
		return (NULL);
	}
	*n = num;
	node = ft_lstnew(n);
	if (node == NULL)
	{
		free(n);
		*err = 1;
	}
	return (node);
}

t_list	*clear_lists(t_list **first, t_list **second)
{
	if (first && *first)
		ft_lstclear(first, free_node);
	if (second && *second)
		ft_lstclear(second, free_node);
	return (NULL);
}

t_list	*ints_to_lst(int nums[], int len)
{
	int		i;
	t_list	*lst;
	t_list	*node;
	int		err;

	err = 0;
	i = 0;
	lst = NULL;
	while (i < len)
	{
		node = create_node(nums[i], &err);
		if (err)
			return (clear_lists(&lst, NULL));
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}

/*
This sorts the elements of lst into two t_lists.
*/
void	sort_elem(t_list *lst, t_list **first, t_list **second, int *err)
{
	int		pivot;			// The pivot to sort elems
	int		current_number;	// The current number to sort
	t_list	*node;			// A new node of the t_list

	*first = NULL;
	*second = NULL;
	if (lst == NULL)		// If there is no list to sort, we leave
		return ;
	pivot = *(int *)(ft_lstlast(lst)->content);	// We get the last element
	while (!*err && lst->next != NULL)	// We separate all elements
	{
		current_number = *(int *)(lst->content);
		node = create_node(current_number, err);	// We create a new node
		if (*err || current_number == pivot)
		{
			clear_lists(first, second);
			return ;
		}
		if (current_number < pivot)
			ft_lstadd_back(first, node);
		else
			ft_lstadd_back(second, node);
		lst = lst->next;
	}
}

t_list	*quick_sort(t_list *lst, int *err)
{
	t_list	*first;			// The first list of numbers (lower of pivot)
	t_list	*second;		// The second list of numbers (higher of pivot)
	t_list	*node;			// A new node of the t_list
	int		pivot;

	// If something fails here, it gets cleared. (Except lst)
	sort_elem(lst, &first, &second, err);
	if (*err)
		return (NULL);
	first = rearrange_list(&first, err);
	if (*err)
		return (clear_lists(&second, NULL));
	pivot = *(int *)(ft_lstlast(lst)->content);	// We get the last element
	node = create_node(pivot, err);	// we create a node with the pivot
	if (*err)
		return (clear_lists(&first, &second));
	ft_lstadd_back(&first, node);
	second = rearrange_list(&second, err);
	if (*err)
		return (clear_lists(&first, NULL));
	ft_lstadd_back(&first, second);
	return (first);
}

t_list	*rearrange_list(t_list **lst, int *err)
{
	t_list	*final_lst;

	if (*lst)
		final_lst = quick_sort(*lst, err);
	else
		final_lst = *lst;
	ft_lstclear(lst, free_node);
	free(*lst);
	return (final_lst);
}

void	print_lst(t_list *lst)
{
	void	*n;

	while (lst->next != NULL)
	{
		printf("%d\n", *(int *)(lst->content));
		lst = lst->next;
	}
	printf("%d\n", *(int *)(lst->content));
}

int main(int argc, char **argv)
{
    int nums[] = {-1, 10, 1, 2, 0, 14};
    int len = 6;
	int	err = 0;

	t_list	*lst;
	t_list	*result;

	lst = ints_to_lst(nums, len);
	if (!lst)
		return (0);
	//print_lst(lst);

	// Here it tries to sort the list. If a malloc fails
	// or there is two elements repeated, err is set to 1.
    result = quick_sort(lst, &err);
	ft_lstclear(&lst, free_node);

	if (!err)
		print_lst(result);
	else
		printf("error");
	return (0);
}
