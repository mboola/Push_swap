/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/14 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_output	*create_strct(int fd, va_list va, int *err)
{
	t_output	*output;

	output = malloc(sizeof(t_output));
	if (output == NULL)
	{
		*err = 1;
		return (NULL);
	}
	output->fd = fd;
	va_copy(output->va, va);
	output->err = err;
	return (output);
}

static int	end(va_list va, int err, int count)
{
	va_end(va);
	if (err)
		return (-1);
	return (count);
}

int	ft_printf(int fd, char const *str, ...)
{
	int			err;
	int			count;
	t_output	*output;
	va_list		va;

	if (str == NULL)
		return (-1);
	err = 0;
	count = 0;
	va_start(va, str);
	output = create_strct(fd, va, &err);
	while (*str != '\0' && !err)
	{
		if (*str == '%')
		{
			str++;
			count += choose_conversion(str, output);
		}
		else
			count += ft_putchar_err(*str, output);
		str++;
	}
	free(output);
	return (end(va, err, count));
}
