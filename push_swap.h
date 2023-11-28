
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct t_node
{
	int		number;
	char	stack_name;
}	t_node;

typedef struct t_list
{
	void			*content;
	struct t_list	*next;
}	t_list;

typedef struct t_stack
{
	char			name;
	size_t			n_elem;
	struct t_list	*nodes;
}	t_stack;

t_stack *create_stack(char name, int *err);
void	clear_stack(t_stack **stk);
t_list	*convert_arg_to_lst(char **argv, int argc, int *err);
t_list	*get_ptr_lst(t_stack *stk, int *err);
t_list	*sort_ptr_lst(t_list **lst, int *err);
void	push_swap(t_stack **stk_a, t_stack **stk_b, t_list **ptr_lst);
void	clear_data(t_stack **stk_a, t_stack **stk_b, t_list	**ptr_lst);

t_list	*clear_ptr_lst(t_list **lst);
t_list	*clear_node_lst(t_list **lst);
//libft
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(char *str, char **rest);
char	**ft_split(char *s, char c);

#endif
