/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reiascan <reiascan@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:29:36 by reiascan          #+#    #+#             */
/*   Updated: 2026/10/23 19:27:35 by reiascan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	count;
	int number;
	char	*str;

	str = "hELICOPtero33";

	number = 15;
	// IMPRIMIR STR (%s)
	ft_printf(" ******  TEST STR (%%s) ****** \n");
	ft_printf(" ------  MI PRINTF  ------ \n");
	count = ft_printf("Hola mi Nombre es: %s\n", "Reinaldo");
	ft_printf("imprime %d caracteres\n", count);
	printf(" ------ PRINTF SYSTEM ------ \n");
	count = printf("Hola mi Nombre es: %s\n", "Reinaldo");
	printf("imprime %d caracteres\n", count);
	// // IMPRIMIR CHAR (%c)
	ft_printf("\n ******  TEST CHAR (%%c) ****** \n");
	ft_printf(" ------  MI PRINTF  ------ \n");
	count = ft_printf("Mi inicial es: %c\n", 'R');
	ft_printf("imprime %d caracteres\n", count);
	printf(" ------ PRINTF SYSTEM ------ \n");
	count = printf("Mi inicial es: %c\n", 'R');
	printf("imprime %d caracteres\n", count);
	// // IMPRIMIR INT (%d || %i)
	ft_printf("\n ******  TEST INT (%%d y  %%i) ****** \n");
	ft_printf(" ------  MI PRINTF  ------ \n");
	count = ft_printf("Lista de numeros = {%d, %i, %d, %i}\n", 42, -15975, 485504, -2147483648);
	ft_printf("imprime %d caracteres\n", count);
	printf(" ------ PRINTF SYSTEM ------ \n");
	count = printf("Lista de numeros = {%d, %i, %d, %li}\n", 42, -15975, 485504, -2147483648);
	printf("imprime %d caracteres\n", count);
	// // IMPRIMIR HEX  (%X)
	ft_printf("\n ******  TEST HEX (%%X) ****** \n");
	ft_printf(" ------  MI PRINTF  ------ \n");
	count = ft_printf("HEX: %X (esperado: 3BF0)\n", 15344);
	ft_printf("imprime %d caracteres\n", count);
	printf(" ------ PRINTF SYSTEM ------ \n");
	count = printf("HEX: %X (esperado: 3BF0)\n", 15344);
	printf("imprime %d caracteres\n", count);
	// // IMPRIMIR hex (%x)
	ft_printf("\n ******  TEST hex (%%x) ****** \n");
	ft_printf(" ------  MI PRINTF  ------ \n");
	count = ft_printf("hex: %x (esperado: 3bf0)\n", 15344);
	ft_printf("imprime %d caracteres\n", count);
	printf(" ------ PRINTF SYSTEM ------ \n");
	count = printf("hex: %x (esperado: 3bf0)\n", 15344);
	printf("imprime %d caracteres\n", count);
	// // IMPRIMIR puntero (%p)
	ft_printf("\n****** TEST POINTER (%%p) ****** \n");
	ft_printf(" ------  MI PRINTF  ------ \n");
	count = ft_printf("String: %s, direccion de memoria: %p\n", str, (void *)&str);
	ft_printf("imprime %d caracteres\n", count);
	count = ft_printf("Cuando ptr == NULL: %p\n", (void *)0);
	ft_printf("imprime %d caracteres\n", count);
	count = ft_printf("Numero: %d, direccion de memoria: %p\n", number, (void *)&number);
	ft_printf("imprime %d caracteres", count);
	printf("\n ------  PRINTF SYSTEM  ------ \n");
	count = printf("String: %s, direccion de memoria: %p\n", str, &str);
	printf("imprime %d caracteres\n", count);
	count = printf("Cuando ptr == NULL: %p\n", (void *)0);
	printf("imprime %d caracteres\n", count);
	count = printf("Numero: %d, direccion de memoria: %p\n", number, &number);
	printf("imprime %d caracteres\n", count);
	// // IMPRIMIR decimal sin signo (%u)
	ft_printf("\n ******  TEST UNIT (%%x) ****** \n");
	ft_printf(" ------  MI PRINTF  ------ \n");
	count = ft_printf("hex: %u (esperado: 4294967295)\n", -1);
	ft_printf("imprime %d caracteres\n", count);
	printf(" ------ PRINTF SYSTEM ------ \n");
	count = printf("hex: %u (esperado: 4294967295)\n", -1);
	printf("imprime %d caracteres\n", count);

	ft_printf("\n ****** EXTRA ****** \n");
	//Limites de long y ulong
	ft_printf(" ------  MI PRINTF  ------ \n");
	ft_printf("LONG_MIN: %p, LONG_MAX: %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("ULONG_MAX: %p, -ULONG_MAX: %p\n", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
	printf("\n ------  PRINTF SYSTEM  ------ \n");
	printf("LONG_MIN: %p, LONG_MAX: %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("ULONG_MAX: %p, -ULONG_MAX: %p\n", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
	return (0);
}