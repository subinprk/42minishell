/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:29 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 13:00:30 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int i, int *length)
{
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (i < 0)
	{
		ft_print_length('-', length);
		ft_print_nbr(i * -1, length);
	}
	if (i >= 0 && i <= 9)
		ft_print_length(i + '0', length);
	if (i > 9)
	{
		ft_print_nbr(i / 10, length);
		ft_print_length(i % 10 + '0', length);
	}
}
