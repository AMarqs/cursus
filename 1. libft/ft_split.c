/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:17:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/05 17:36:57 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	dst_free(char **dst, size_t i)
{
	while (i > 0)
	{
		free (dst[i - 1]);
		i--;
	}
	free (dst);
}

static char	**split_rows(char const *s, char c, char **dst, size_t	count_word)
{
	size_t			i;
	size_t			row;
	unsigned int	start;

	i = 0;
	row = count_word;
	while (s[i] != '\0' && row > 0)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		dst[count_word - row] = ft_substr(s, start, (i - start));
		if (dst[count_word - row] == NULL)
		{
			dst_free (dst, (count_word - row));
			return (NULL);
		}
		row--;
	}
	dst[count_word] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	count_word;

	count_word = count_words(s, c);
	dst = (char **)malloc((count_word + 1) * sizeof(char *));
	if (dst == NULL)
		return (NULL);
	dst = split_rows(s, c, dst, count_word);
	return (dst);
}
