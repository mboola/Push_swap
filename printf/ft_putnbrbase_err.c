/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:25:21 by mpovill-          #+#    #+#             */
/*   Updated: 2023/09/18 15:25:28 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_nbr_long(unsigned long num, char *base, t_output *op, int len)
{
	int	count;

	if (num / len < 1)
		return (ft_putchar_err(base[num], op));
	else
	{
		count = put_nbr_long(num / len, base, op, len);
		if (!*(op->err))
			count += ft_putchar_err(base[(num % len)], op);
		return (count);
	}
}

int	put_unslong_base(unsigned long nbr, char *base, t_output *op, int len)
{
	return (put_nbr_long(nbr, base, op, len));
}

int	put_unsint_base(unsigned int nbr, char *base, t_output *op, int len)
{
	unsigned long	n;

	n = 0 + nbr;
	return (put_nbr_long(n, base, op, len));
}

int	put_int_base_err(int nbr, char *base, t_output *op, int len)
{
	unsigned int	num;
	int				count;
	unsigned long	n;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_err('-', op);
		num = nbr * -1;
	}
	else
		num = nbr;
	n = 0 + num;
	if (!*(op->err))
		return (put_nbr_long(n, base, op, len) + count);
	return (count);
}
