/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:06:53 by reiascan          #+#    #+#             */
/*   Updated: 2026/10/23 19:23:55 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned(unsigned long num, int base)
{
	int		count;
	char	*real_base;

	real_base = "0123456789abcdef";
	count = 0;
	if (num / base != 0)
		count += print_unsigned((num / base), base);
	count += print_char(real_base[num % base]);
	return (count);
}

int	print_mem_dir(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (write (1, "(nil)", 5));
	count = print_str("0x");
	count += print_unsigned(ptr, 16);
	return (count);
}
