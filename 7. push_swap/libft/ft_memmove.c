/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:51 by albmarqu          #+#    #+#             */
/*   Updated: 2024/01/18 19:36:52 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst1 > src1)
	{
		while (len-- > 0)
			dst1[len] = src1[len];
	}
	else
	{
		while (i++ < len)
			dst1[i - 1] = src1[i - 1];
	}
	return (dst);
}
