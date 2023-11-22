/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:46 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 13:00:48 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int u, int *length)
{
	if (u >= 10)
		ft_print_unsigned(u / 10, length);
	ft_print_length(u % 10 + '0', length);
}
