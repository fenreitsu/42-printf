/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_evaluator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:05:35 by reiascan          #+#    #+#             */
/*   Updated: 2026/10/23 19:23:48 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_evaluator(char var_id, va_list ap)
{
	int	count;

	count = 0;
	if (var_id == 'c')
		count += print_char(va_arg(ap, int));
	else if (var_id == 's')
		count += print_str(va_arg(ap, char *));
	else if (var_id == 'i' || var_id == 'd')
		count += print_digit((long)va_arg(ap, int), 10, var_id);
	else if (var_id == 'u')
		count += print_digit((long)va_arg(ap, unsigned int), 10, var_id);
	else if (var_id == 'p')
		count += print_mem_dir((unsigned long)va_arg(ap, unsigned long));
	else if (var_id == 'x' || var_id == 'X')
		count += print_digit((long)va_arg(ap, unsigned int), 16, var_id);
	else if (var_id == '%')
		count += write (1, &var_id, 1);
	else
		count += write (1, &var_id, 1);
	return (count);
}
