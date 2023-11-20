/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:12:40 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/25 19:12:44 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_num(void)
{
	int sum;

	sum = 0;
	while (*g_str <= '9' && *g_str >= '0')
	{
		sum = sum * 10 + (*g_str - '0');
		g_str++;
	}
	return (sum);
}

void	treat_minus_flag(t_flags *flags)
{
	flags->minus = 1;
	g_str++;
}

void	treat_zero_flag(t_flags *flags)
{
	flags->zero = 1;
	g_str++;
}

void	treat_asterix_flag(t_flags *flags)
{
	flags->width = va_arg(g_ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	g_str++;
}

void	treat_dot_flag(t_flags *flags)
{
	flags->dot = 1;
	g_str++;
	if (*g_str <= '9' && *g_str >= '0')
	{
		flags->prec = ft_get_num();
	}
	if (*g_str == '*')
	{
		flags->prec = va_arg(g_ap, int);
		g_str++;
	}
}
