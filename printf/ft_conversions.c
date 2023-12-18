/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:58:29 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/14 12:58:30 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:58:29 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/14 12:58:30 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_err(char c, t_output *output)
{
	if (write(output->fd, &c, 1) < 0)
		*(output->err) = -1;
	return (1);
}

int	ft_putstr_err(char *str, t_output *output)
{
	int	count;

	if (str == NULL)
	{
		if (write(output->fd, "(null)", 6) < 0)
			*(output->err) = -1;
		return (6);
	}
	count = 0;
	while (*str != '\0' && !*(output->err))
	{
		ft_putchar_err(*str, output);
		str++;
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr, t_output *output)
{
	unsigned long	addr;

	if (write(output->fd, "0x", 2) < 0)
		*(output->err) = -1;
	if (!*(output->err))
	{
		addr = (unsigned long)ptr;
		return (put_unslong_base(addr, HEXBASELOW, output, 16) + 2);
	}
	return (0);
}

int	choose_conversion(char const *str, t_output *op)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = ft_putchar_err(va_arg(op->va, int), op);
	else if (*str == 's')
		count = ft_putstr_err(va_arg(op->va, char *), op);
	else if (*str == 'u')
		count = put_unsint_base(va_arg(op->va, int), DECBASE, op, 10);
	else if (*str == 'p')
		count = ft_putptr(va_arg(op->va, void *), op);
	else if (*str == 'i' || *str == 'd')
		count = put_int_base_err(va_arg(op->va, int), DECBASE, op, 10);
	else if (*str == 'x')
		count = put_unsint_base(va_arg(op->va, int), HEXBASELOW, op, 16);
	else if (*str == 'X')
		count = put_unsint_base(va_arg(op->va, int), HEXBASEHIG, op, 16);
	else if (*str == '%')
		count = ft_putchar_err('%', op);
	else
		*(op->err) = -1;
	return (count);
}
