/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:20:00 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/21 16:20:06 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_flags flags)
{
	int		i;
	char	c;

	(c = (*g_str == '%' ? '%' : va_arg(g_ap, int)));
	i = 0;
	if (flags.width == 0)
		flags.width = 1;
	if (flags.minus == 0)
		while (i < flags.width)
		{
			if (i < flags.width - 1)
				(flags.zero == 0) ? ft_putchar_fd(' ', 1) :
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(c, 1);
			i++;
		}
	if (flags.minus == 1)
		while (i < flags.width)
		{
			(i >= 1) ? ft_putchar_fd(' ', 1) : ft_putchar_fd(c, 1);
			i++;
		}
}
