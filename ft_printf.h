/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:32:43 by reiascan          #+#    #+#             */
/*   Updated: 2026/10/23 19:24:04 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_str(char *str);
int	print_char(int c);
int	print_digit(long num, int base, char var_id);
int	print_mem_dir(unsigned long ptr);
int	print_evaluator(char var_id, va_list ap);
int	ft_printf(char const *fmt, ...);

#endif
