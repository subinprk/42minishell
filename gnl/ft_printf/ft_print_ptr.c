/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:34 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 13:00:37 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(size_t ptr, int *length)
{
	char	str[50];
	char	*hex_c;
	int		i;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*length) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*length) += 2;
	hex_c = "0123456789abcdef";
	i = 0;
	while (ptr)
	{
		str[i] = hex_c[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
	{
		ft_print_length(str[i], length);
	}
}
