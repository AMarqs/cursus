/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:54:22 by albmarqu          #+#    #+#             */
/*   Updated: 2024/07/11 18:12:21 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ftp_putchar(int c);
int	ftp_putstr(char *str);
int	ftp_putnbr(long n, int bytes);
int	ftp_puthex(unsigned long n, char cap, int bytes);
int	isput(va_list args);

#endif