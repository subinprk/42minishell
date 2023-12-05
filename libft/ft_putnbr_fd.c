/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:59:36 by subpark           #+#    #+#             */
/*   Updated: 2023/06/01 11:04:35 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		str = '0' + (n % 10);
	}
	else if (n < 10)
		str = '0' + n;
	write(fd, &str, 1);
	return ;
}
