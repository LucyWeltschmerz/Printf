/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:49:40 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/22 16:49:47 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.prec = 0;
	flags.type = 0;
	return (flags);
}

void	type(t_flags flags)
{
	if (*g_str == 'c' || *g_str == '%')
		ft_print_char(flags);
	else if (*g_str == 's')
	{
		flags.type = 's';
		ft_print_str(va_arg(g_ap, char *), flags);
	}
	if (*g_str == 'i' || *g_str == 'd' || *g_str == 'x' ||
		*g_str == 'X' || *g_str == 'p' || *g_str == 'u')
	{
		flags.type = *g_str;
		ft_print_digit(flags);
	}
}

t_flags	check_flags(t_flags flags)
{
	while (*g_str == '-' || *g_str == '.' ||
	*g_str == '*' || (*g_str <= '9' && *g_str >= '0'))
	{
		if (*g_str == '-')
			treat_minus_flag(&flags);
		if (*g_str == '0')
			treat_zero_flag(&flags);
		if (*g_str <= '9' && *g_str >= '1')
			flags.width = ft_get_num();
		if (*g_str == '*')
			treat_asterix_flag(&flags);
		if (*g_str == '.')
			treat_dot_flag(&flags);
	}
	return (flags);
}

int		ft_printf(const char *format, ...)
{
	char	*str_begin;
	t_flags	flags;

	g_char_count = 0;
	g_str = ft_strdup(format);
	str_begin = g_str;
	va_start(g_ap, format);
	while (*g_str)
	{
		if (*g_str == '%')
		{
			g_str++;
			flags = init_flags();
			flags = check_flags(flags);
			type(flags);
		}
		else
		{
			ft_putchar_fd(*g_str, 1);
		}
		g_str++;
	}
	free(str_begin);
	va_end(g_ap);
	return (g_char_count);
}
