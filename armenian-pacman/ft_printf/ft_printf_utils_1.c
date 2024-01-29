/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:27:11 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/04/29 18:27:13 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *word)
{
	size_t	size;

	if (!word)
		return (0);
	size = 0;
	while (word[size] != '\0')
	{
		size++;
	}
	return (size);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, sizeof(char) * ft_strlen(s));
}

int	print_char(char character)
{
	ft_putchar_fd(character, 1);
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	else
		ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}
