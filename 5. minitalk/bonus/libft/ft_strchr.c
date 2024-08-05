/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:39:58 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/05 17:42:12 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;
	char	*s1;

	c1 = (char)c;
	s1 = (char *)s;
	while (*s1)
	{
		if (*s1 == c1)
			return (s1);
		s1++;
	}
	if (c1 == '\0')
		return (s1);
	return (NULL);
}
