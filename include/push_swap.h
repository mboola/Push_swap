
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

//structs
typedef struct t_node
{
	int		number;
	char	stack_name;
}	t_node;

typedef struct t_list
{
	void			*content;
	struct t_list	*next;
	struct t_list	*previous;
}	t_list;

typedef struct t_stack
{
	char			name;
	size_t			n_elem;
	struct t_list	*top_node;
	struct t_list	*bottom_node;
}	t_stack;

//??
t_stack *create_stack(char name, int *err);
void	clear_stack(t_stack **stk);
t_list	*convert_arg_to_lst(char **argv, int argc, int *err);
t_list	*get_ptr_lst(t_stack *stk, int *err);
t_list	*quick_sort(t_list *lst, int *err);
void	push_swap(t_stack **stk_a, t_stack **stk_b, t_list **ptr_lst);
void	clear_data(t_stack **stk_a, t_stack **stk_b, t_list	**ptr_lst);

//??
t_list	*clear_ptr_lst(t_list **lst);
t_list	*clear_node_lst(t_list **lst);

//libft
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_atoi(char *str, char **rest);
char	**ft_split(char *s, char c);

void	ft_lstadd_n(t_list **lst, t_list *node, int index);
t_list	*extract_n(t_list **lst, int index);
int		find_inside_lst(t_list *lst, int num);

//??
t_list	*extract_last(t_list **lst);
t_list	*extract_first(t_list **lst);
int		get_node_number_from_lst(t_list *ptr_lst);
void	push_argv_in_stack(int argc, char **argv, t_stack *stk, int *err);
t_list	*create_lst_ptr_to_nodes(t_stack *stk, int *err);

//operations we can perform to the stack
void	swap(t_stack *stk);
void	rotate(t_stack *stk);
void	reverse_rotate(t_stack *stk);

//operations that check if the stack gets sorted if performed
int		swap_sorted(t_stack *stk);
int		rotate_sorted(t_stack *stk);
int		reverse_rotate_sorted(t_stack *stk);

//general use
int		is_sorted(t_stack *stk);
int		can_swap(t_stack *stk);
int		can_reverse_rotate(t_stack *stk);
int		find_shortest_path(t_stack *stk, t_list *node);

//operations displayed by the terminal
void	perform_push(t_stack *stk_org, t_stack *stk_dest);
void	perform_reverse_rotate(t_stack *stk);
void	perform_double_reverse_rotate(t_stack *stk_a, t_stack *stk_b);
void	perform_rotate(t_stack *stk);
void	perform_double_rotate(t_stack *stk_a, t_stack *stk_b);
void	perform_swap(t_stack *stk);
void	perform_double_swap(t_stack *stk_a, t_stack *stk_b);

//core stack methods
void	push_top(t_stack *stk, t_list *node);
void	push_bottom(t_stack *stk, t_list *node);
t_list	*pop_top(t_stack *stk);
t_list	*pop_bottom(t_stack *stk);

//data acces operations
int		get_bottom_value(t_stack *stk);
int		get_top_value(t_stack *stk);
int		get_higher_value(t_list *lst);
int		get_lower_value(t_list *lst);
int		get_value_stk(t_list *stk_lst);
int		get_value_lst(t_list *ptr_lst);

//??
int		get_num_at(t_stack *stk, size_t index, int from_bottom);

//sorting algorithms
void	sort_2(t_stack *stk_a);
void	sort_3(t_stack *stk_a, t_list *lst);
void	sort_4(t_stack *stk_a, t_stack *stk_b, t_list *lst);
void	sort_5(t_stack *stk_a, t_stack *stk_b, t_list *lst);
void	sort_n(t_stack *stk_a, t_stack *stk_b, t_list *lst);

#endif
