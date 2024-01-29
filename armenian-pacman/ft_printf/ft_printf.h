/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:11:43 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/04/17 20:11:46 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*		INCLUDES				*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*		FUNCTIONS				*/
int		print_string(char *word);
int		switch_case(char letter, va_list args);
int		ft_printf(const char *sentence, ...);
size_t	ft_strlen(const char *word);
void	ft_putstr_fd(char *s, int fd);
int		print_char(char character);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		print_number(int number);
int		print_unsigned(unsigned int number);
char	get_char(int number, int capitalize);
int		print_hexadecimal(unsigned long number, int capitalize);
int		print_pointer(void *argument);

#endif
