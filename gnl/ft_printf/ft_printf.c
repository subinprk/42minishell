/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:53 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 13:00:54 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_checker(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		ft_print_str(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_print_nbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_print_unsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_print_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_print_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_print_ptr(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_print_length(va_arg(*args, int), len);
	else if (s == '%')
		ft_print_length('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	if (!str)
		return (-1);
	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_checker(str[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_print_length((char)str[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
