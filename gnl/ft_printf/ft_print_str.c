/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:41 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 13:00:42 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *c, int *length)
{
	size_t	i;

	i = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (c[i] != '\0')
	{
		ft_print_length(c[i], length);
		i++;
	}
}
