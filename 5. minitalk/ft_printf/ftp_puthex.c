/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_puthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:04:35 by albmarqu          #+#    #+#             */
/*   Updated: 2024/07/11 19:56:00 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftp_puthex(unsigned long n, char cap, int bytes)
{
	char	*hex;

	if (cap == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		bytes += ftp_puthex((n / 16), cap, bytes);
	n = (n % 16);
	write(1, &hex[n], 1);
	bytes++;
	return (bytes);
}

int	isput(va_list args)
{
	int				bytes;
	unsigned long	p;

	p = va_arg(args, unsigned long);
	if (p == 0)
		bytes = write(1, "(nil)", 5);
	else
	{
		bytes = write(1, "0x", 2);
		bytes += ftp_puthex(p, 'x', 0);
	}
	return (bytes);
}
