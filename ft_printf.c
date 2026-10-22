/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:43:40 by reiascan          #+#    #+#             */
/*   Updated: 2026/10/22 22:43:21 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *fmt, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, fmt);
	count = 0;
	while (*fmt != 0)
	{
		if (*fmt == '%')
			count += print_evaluator(*(++fmt), ap);
		else
			count += write (1, fmt, 1);
		++fmt;
	}
	va_end (ap);
	return (count);
}
