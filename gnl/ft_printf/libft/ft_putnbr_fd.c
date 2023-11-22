/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:57:08 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 12:57:10 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
			return ;
		}
		n = -n;
	}
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-1, 0);
	return (0);
}*/
