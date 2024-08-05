/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:19:15 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/05 17:35:23 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strnum(char *dst, int n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		dst[0] = '-';
	}
	while (i < len)
	{
		if (n >= 10)
		{
			dst[len - i - 1] = (n % 10) + '0';
			n = (n / 10);
		}
		else
		{
			dst[len - i - 1] = n + '0';
			break ;
		}
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

static int	numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = (n / 10);
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dst;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	dst = (char *)malloc((numlen(n) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst = strnum(dst, n, numlen(n));
	return (dst);
}
