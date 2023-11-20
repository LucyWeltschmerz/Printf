/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string_from.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:41:59 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/26 14:42:10 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_string_from_int(t_flags flags, int d)
{
	char			*str;
	int				min;
	unsigned int	digit;
	char			*minus;

	min = (d < 0) ? -1 : 1;
	digit = (d < 0) ? (-1 * d) : d;
	if (flags.dot == 1 && flags.prec == 0 && digit == 0)
		str = ft_strdup("\0");
	else
	{
		if (!(str = ft_itoa_base(digit, 10, flags.type)))
			return (NULL);
	}
	if (min == -1)
	{
		minus = ft_strdup("-");
		if (!(str = ft_strjoin(minus, str)))
			return (NULL);
	}
	return (str);
}

char	*get_string_from_u(t_flags flags)
{
	char			*str;
	unsigned int	u;

	u = (unsigned int)va_arg(g_ap, void *);
	if (flags.dot == 1 && flags.prec == 0 && u == 0)
		str = ft_strdup("\0");
	else
	{
		if (!(str = ft_itoa_base(u, 10, flags.type)))
			return (NULL);
	}
	return (str);
}

char	*get_string_from_hex(t_flags flags)
{
	char		*str;
	uintmax_t	x;

	x = (unsigned int)va_arg(g_ap, void *);
	if (flags.dot == 1 && flags.prec == 0 && x == 0)
		str = ft_strdup("\0");
	else
	{
		if (!(str = ft_itoa_base(x, 16, flags.type)))
			return (NULL);
	}
	return (str);
}

char	*get_string_from_p(t_flags flags)
{
	char		*ox;
	char		*tmp;
	char		*str;
	uintmax_t	x;

	x = (uintmax_t)va_arg(g_ap, void *);
	ox = ft_strdup("0x");
	if (!x)
		tmp = (flags.dot == 0) ? ft_strdup("0") : ft_strdup("\0");
	else
	{
		if (!(tmp = ft_itoa_base(x, 16, flags.type)))
			return (NULL);
	}
	str = ft_strjoin(ox, tmp);
	return (str);
}

int		get_len_to_print(t_flags *flags, int strlen, int d)
{
	int	len_to_print;

	if (flags->zero == 1 && flags->width > strlen &&
	flags->dot == 0 && flags->minus == 0)
		len_to_print = flags->width;
	else if (flags->prec >= strlen)
	{
		if (d < 0)
			len_to_print = flags->prec + 1;
		else if (flags->type == 'p')
			len_to_print = flags->prec + 2;
		else
			len_to_print = flags->prec;
	}
	else
		len_to_print = strlen;
	if (flags->width < len_to_print)
		flags->width = len_to_print;
	return (len_to_print);
}
