/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*cleanup(char *str, char *n)
{
	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	*n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*n *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	return (str);
}

int	ft_atoi(char *str, char *err)
{
	unsigned int	num;
	unsigned int	min;
	int				final_num;
	char			n;

	str = cleanup(str, &n);
	num = 0;
	min = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > min)
			min = num;
		else
		{
			*err = 1;
			return (0);
		}
		str++;
	}
	if ((num - 1 > MAX_INT && n == -1) || (num > MAX_INT) || *str != '\0')
		*err = 1;
	else
		final_num = num * n;
	return (final_num);
}
