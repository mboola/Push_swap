
#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count) != '\0')
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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

static int	count_strings(const char *str, char c)
{
	int	n_strs;
	int	n_chars;

	n_chars = 0;
	n_strs = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			if (n_chars != 0)
			{
				n_chars = 0;
				n_strs++;
			}
			str++;
		}
		else
		{
			n_chars++;
			str++;
		}
	}
	if (n_chars != 0)
		n_strs++;
	return (n_strs);
}

static int	add_str_to_matrix(const char *str, int word, int i, char **matrix)
{
	*(matrix + i) = ft_substr(str, 0, word);
	if (*(matrix + i) == NULL)
	{
		while (i >= 0)
		{
			free(*(matrix + i));
			i--;
		}
		free(matrix);
		return (0);
	}
	return (1);
}

static int	create_matrix(const char *str, char c, int length, char **matrix)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (i < length && *(str + word) != '\0')
	{
		if (*(str + word) == c && word != 0)
		{
			if (add_str_to_matrix(str, word, i, matrix) == 0)
				return (0);
			i++;
			str = str + word;
			word = 0;
		}
		else if (*str == c)
			str++;
		else
			word++;
	}
	if (word != 0)
		if (add_str_to_matrix(str, word, i, matrix) == 0)
			return (0);
	return (1);
}

char	**ft_split(char *s, char c)
{
	int		length;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	length = count_strings(s, c);
	matrix = malloc(sizeof(char *) * (length + 1));
	if (matrix == NULL)
		return (NULL);
	if (create_matrix(s, c, length, matrix) == 0)
		return (NULL);
	*(matrix + length) = NULL;
	return (matrix);
}
