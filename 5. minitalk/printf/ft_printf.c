/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:53:58 by albmarqu          #+#    #+#             */
/*   Updated: 2024/07/11 18:02:12 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	var_type(char s, va_list args)
{
	int	bytes;

	bytes = 0;
	if (s == 'c')
		bytes = ftp_putchar(va_arg(args, int));
	else if (s == 's')
		bytes = ftp_putstr(va_arg(args, char *));
	else if (s == 'p')
		bytes = isput(args);
	else if (s == 'd' || s == 'i')
		bytes = ftp_putnbr(va_arg(args, int), 0);
	else if (s == 'u')
		bytes = ftp_putnbr(va_arg(args, unsigned int), 0);
	else if (s == 'x' || s == 'X')
		bytes = ftp_puthex(va_arg(args, unsigned int), s, 0);
	else if (s == '%')
		bytes = write(1, "%", 1);
	return (bytes);
}

int	ft_printf(char const *s, ...)
{
	va_list			args;
	int				bytes;
	int				i;

	bytes = 0;
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			bytes += var_type(s[i], args);
		}
		else
			bytes += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (bytes);
}
