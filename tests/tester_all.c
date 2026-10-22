/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:29:36 by reiascan          #+#    #+#             */
/*   Updated: 2026/10/22 22:31:19 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	main(void)
{
	int		age;
	int		count;
	char	c;
	// char	*name;

	age = 22;
	c = 'R';
	// name = "Pepito";
	ft_printf("hola mi inicial es: %c y mi edad: %d\n", c, age);
	count = ft_printf("hola mi inicial es: %c y mi edad: %d\n", c, age);
	ft_printf("Mi print imprime %d caracteres\n", count);
	ft_printf("HEX: %X\n", 255);
	ft_printf("hex: %x\n", 255);

	return (0);
}