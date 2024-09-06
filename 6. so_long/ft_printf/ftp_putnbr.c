/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:33:34 by albmarqu          #+#    #+#             */
/*   Updated: 2024/02/07 22:03:03 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftp_putnbr(long n, int bytes)
{
	int	sign;

	sign = 0;
	if (n == -2147483648)
		bytes = write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			write(1, "-", 1);
			sign = 1;
		}
		if (n >= 10)
			bytes = ftp_putnbr((n / 10), bytes);
		n = (n % 10) + '0';
		write (1, &n, 1);
		bytes++;
		if (sign == 1)
			bytes++;
	}
	return (bytes);
}
