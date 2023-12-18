/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:09:39 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/14 12:11:04 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef HEXBASELOW
#  define HEXBASELOW "0123456789abcdef"
# endif
# ifndef HEXBASEHIG
#  define HEXBASEHIG "0123456789ABCDEF"
# endif
# ifndef DECBASE
#  define DECBASE "0123456789"
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_output
{
	int		fd;
	int		*err;
	va_list	va;
}	t_output;

int	ft_printf(int fd, char const *str, ...);
int	choose_conversion(char const *str, t_output *output);
int	ft_putchar_err(char c, t_output *output);
int	ft_putstr_err(char *str, t_output *output);
int	ft_putptr(void *ptr, t_output *output);
int	put_unslong_base(unsigned long nbr, char *base, t_output *op, int len);
int	put_unsint_base(unsigned int nbr, char *base, t_output *op, int len);
int	put_int_base_err(int nbr, char *base, t_output *op, int len);

#endif
