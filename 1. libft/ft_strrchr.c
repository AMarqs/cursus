/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:57:56 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/05 17:58:46 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	c1;
	char	*s1;

	last = NULL;
	c1 = (char)c;
	s1 = (char *)s;
	while (*s1)
	{
		if (*s1 == c1)
			last = s1;
		s1++;
	}
	if (c1 == '\0')
		return (s1);
	return (last);
}
