/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:58 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 13:01:00 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include "libft/libft.h"

void	ft_print_length(char c, int *length);
void	ft_print_str(char *c, int *length);
void	ft_print_nbr(int i, int *length);
void	ft_print_hex(unsigned int x, int *length, char z);
void	ft_print_unsigned(unsigned int u, int *length);
void	ft_print_ptr(size_t ptr, int *length);

int		ft_printf(const char *str, ...);

#endif
