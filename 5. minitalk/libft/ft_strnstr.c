/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:54:31 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/05 17:53:59 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;

	i = 0;
	h = (char *)haystack;
	if (*needle == '\0')
		return (h);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i] == needle[j]) && needle[j] && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (h + (i - j));
		i = i - j;
		i++;
	}
	return (NULL);
}
