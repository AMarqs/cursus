/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:47:18 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/05 18:20:13 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_char(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (s1[i] && set_char(s1[i], set))
		i++;
	while (set_char(s1[j], set) && (j - i) > 0)
		j--;
	dst = (char *)malloc((j - i + 2) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	if (i != j)
		while (i <= j)
			dst[k++] = s1[i++];
	else
		dst[k++] = s1[i];
	dst[k] = '\0';
	return (dst);
}
