/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:09:18 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/05/21 12:45:37 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *word)
{
	int	i;
	int	len;

	if (word == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	len = ft_strlen(word);
	while (i < len)
	{
		ft_putchar_fd(word[i], 1);
		i++;
	}
	return (ft_strlen(word));
}

int	switch_case(char letter, va_list args)
{
	unsigned int	dummy;

	if (letter == 's')
		return (print_string(va_arg(args, char *)));
	else if (letter == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (letter == 'd' || letter == 'i')
		return (print_number(va_arg(args, int)));
	else if (letter == 'c')
		return (print_char(va_arg(args, int)));
	else if (letter == 'u')
	{
		dummy = (va_arg(args, unsigned int));
		if (dummy == 0)
			return (write(1, "0", 1));
		return (print_unsigned(dummy));
	}
	else if (letter == 'x')
		return (print_hexadecimal((va_arg(args, unsigned int)), 0));
	else if (letter == 'X')
		return (print_hexadecimal((va_arg(args, unsigned int)), 1));
	else if (letter == '%')
		return (print_char('%'));
	return (0);
}

// int	switch_case(char letter, void *argument)
// {
// 	if (letter == 's')
// 		return (print_string((char *)argument));
// 	else if (letter == 'p')
// 		return (print_pointer(argument));
// 	else if (letter == 'd' || letter == 'i')
// 		return (print_number((int) argument));
// 	else if (letter == 'c')
// 		return (print_char((char) argument));
// 	else if (letter == 'u')
// 	{
// 		if ((unsigned int)argument == 0)
// 			return (write(1, "0", 1));
// 		return (print_unsigned(((unsigned int) argument)));
// 	}
// 	else if (letter == 'x')
// 		return (print_hexadecimal((unsigned int) argument, 0));
// 	else if (letter == 'X')
// 		return (print_hexadecimal((unsigned int) argument, 1));
// 	else if (letter == '%')
// 		return (print_char('%'));
// 	return (0);
// }

int	ft_printf(const char *sentence, ...)
{
	va_list	args;
	int		i;
	int		full_length;
	int		len;

	i = -1;
	full_length = 0;
	len = ft_strlen(sentence);
	va_start (args, sentence);
	while (++i < len)
	{
		if ((sentence[i] == '%') && (len != i))
		{
			if (sentence[i + 1] != '%')
				full_length += switch_case(sentence[i + 1], args);
			else
				full_length += switch_case(sentence[i + 1], NULL);
			i++;
		}
		else
			full_length += write(1, &sentence[i], 1);
	}
	va_end (args);
	return (full_length);
}

// #include <stdio.h>
// int main()
// {
//   //int number = 429496295;
// //   char * name = "ARmen";
// //   char * add = "address";
// //   int number = 8;
// 	int a = 0;
// 	// print_hexadecimal(123, 0);
// 	// printf("%d %d\n", a, b);
// 	 = ft_printf("%u %u %u\n", UINT_MAX, 123, 456);
// ", ft_printf("\nA RANDOM %s TEXT NULL", NULL));
// // //   return 0;

// // }
