/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:50:38 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/05 17:18:46 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b1;
	unsigned char	c1;

	b1 = (unsigned char *)b;
	c1 = (unsigned char)c;
	while (len > 0)
	{
		b1[len - 1] = c1;
		len--;
	}
	return (b);
}
