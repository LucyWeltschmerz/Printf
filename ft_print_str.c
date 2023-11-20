/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:10:21 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/22 16:10:31 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, t_flags flags)
{
	int i;
	int strlen;
	int len_to_print;

	if (!s)
		s = "(null)";
	strlen = ft_strlen(s);
	(len_to_print = (flags.prec < strlen && flags.dot == 1
	&& flags.prec >= 0) ? flags.prec : strlen);
	if (flags.width < len_to_print)
		flags.width = len_to_print;
	i = -1;
	while (flags.minus == 0 && ++i < flags.width)
	{
		if (i < flags.width - len_to_print)
			(flags.zero == 0) ? ft_putchar_fd(' ', 1) :
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(*(s++), 1);
	}
	while (flags.minus == 1 && ++i < flags.width)
		(i >= len_to_print) ? ft_putchar_fd(' ', 1) :
		ft_putchar_fd(*(s++), 1);
}
