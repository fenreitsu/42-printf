/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:39:32 by reiascan          #+#    #+#             */
/*   Updated: 2026/10/22 22:26:37 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long num, int base, char var_id)
{
	int count;
	char	*real_base;

	if  (var_id == 'd' || var_id == 'i' || var_id == 'u')
		real_base = "0123456789";
	if  (var_id == 'X')
		real_base = "0123456789ABCDEF";
	if  (var_id == 'x')
		real_base = "0123456789abcdef";

	count = 0;
	if  (num < 0)
	{
		count += print_char('-');
		count += print_digit(-num, base,var_id);
	}
	else
	{
		if (num / base != 0)
			count += print_digit((num / base), base, var_id);
		count += print_char(real_base[num % base]);
	}
	return (count);
}