/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpovill- <mpovill-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:11:32 by mpovill-          #+#    #+#             */
/*   Updated: 2023/12/19 12:20:50 by mpovill-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count) != '\0')
		count++;
	return (count);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(src);
	if (dstsize == 0)
		return (size);
	i = 0;
	while (*(src + i) != '\0' && i < dstsize - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	size;

	if (s == NULL)
		size = 1;
	else
	{
		s_len = ft_strlen(s);
		if (start > s_len)
			size = 1;
		else if (len > s_len - start)
			size = s_len - start + 1;
		else
			size = len + 1;
	}
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	if (start > s_len)
		*str = '\0';
	else
		ft_strlcpy(str, s + start, size);
	return (str);
}
