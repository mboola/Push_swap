/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

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

//libft
int		ft_atoi(char *str, char *err);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*lst_separate(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*extract_last(t_list **lst);
t_list	*extract_first(t_list **lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);

//core stack methods
void	push_top(t_stack *stk, t_list *node);
void	push_bottom(t_stack *stk, t_list *node);
t_list	*pop_top(t_stack *stk);
t_list	*pop_bottom(t_stack *stk);

//operations we can perform to the stack
void	swap(t_stack *stk);
void	rotate(t_stack *stk);
void	reverse_rotate(t_stack *stk);

//operations displayed by the terminal
void	perform_push(t_stack *stk_org, t_stack *stk_dest);
void	perform_reverse_rotate(t_stack *stk);
void	perform_double_reverse_rotate(t_stack *stk_a, t_stack *stk_b);
void	perform_rotate(t_stack *stk);
void	perform_double_rotate(t_stack *stk_a, t_stack *stk_b);
void	perform_swap(t_stack *stk);
void	perform_double_swap(t_stack *stk_a, t_stack *stk_b);

//quick_sort
t_list	*quick_sort(t_list *lst, char *err);

//auxiliary functions used to sort the stacks
int		is_sorted(t_stack *stk);
int		is_inverse_sorted(t_stack *stk);
int		can_swap(t_stack *stk);
int		swap_sorted(t_stack *stk);

void	push_swap(t_stack **stk_a, t_stack **stk_b, t_list **ptr_lst);

//sorting algorithms
void	sort_2(t_stack *stk_a);
void	inverse_sort_2(t_stack *stk);
void	sort_3(t_stack *stk_a);
void	inverse_sort_3(t_stack *stk);
void	sort_4(t_stack *stk_a, t_stack *stk_b, t_list *lst);
void	sort_5(t_stack *stk_a, t_stack *stk_b, t_list *lst);
void	sort_n(t_stack *stk_a, t_stack *stk_b, t_list *lst);

int		push_values_sorted(t_stack *stk_origin, t_stack *stk_dest, int n_elem);
int		push_values_invsorted(t_stack *stk_org, t_stack *stk_dest, int n_elem);
void	rotate_elem(t_stack *stk, int n_elem);
void	push_elem(t_stack *stk_a, t_stack *stk_b, int n_elem);
t_list	*get_pivot(t_list *lst);
int		push_higher_values(t_stack *stk_org, t_stack *stk_dest, t_list *pivot);
void	push_lower_values(t_stack *stk_org, t_stack *stk_dest, t_list *pivot);
int		get_len_to_end(t_list *lst);
int		get_len_to_start(t_list *lst);

//checking validity of arguments
void	initialize_stk_elem(int argc, char **argv, t_stack *stk, char *err);

//clear the reserved memory
void	clear_stack(t_stack **stk);
t_list	*clear_ptr_lst(t_list **lst);
void	clear_data(t_stack **stk_a, t_stack **stk_b, t_list	**ptr_lst);

//stack methods
t_stack	*create_stack(char name, char *err);
void	put_elem_on_top(t_stack *stk, t_list *lst);
int		get_value_stk(t_list *stk_lst);
int		get_bottom_value(t_stack *stk);
int		get_top_value(t_stack *stk);

//lst of ptr methods
int		find_shortest_path(t_list *node);
int		find_inside_lst(t_list *lst, int num);
int		get_higher_value(t_list *lst);
int		get_lower_value(t_list *lst);
int		get_value_lst(t_list *ptr_lst);
int		get_stk_lst(t_list *ptr_lst);
t_list	*create_lst_ptr_to_nodes(t_stack *stk, char *err);

//printf
int		ft_printf(int fd, char const *str, ...);

#endif
