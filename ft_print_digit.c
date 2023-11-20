/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:17:21 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/21 16:17:28 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_convert(int nbr, char type)
{
	if (nbr >= 10)
	{
		if (type == 'x' || type == 'p')
			return (nbr - 10 + 'a');
		else
			return (nbr - 10 + 'A');
	}
	else
		return (nbr + '0');
}

char	*ft_itoa_base(uintmax_t d, int base, char type)
{
	uintmax_t	tmp;
	int			i;
	char		*str;

	tmp = d;
	i = 0;
	while (tmp >= (unsigned int)base)
	{
		tmp = tmp / (unsigned int)base;
		i++;
	}
	if (!(str = (char *)malloc(i + 2)))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = d % base;
		str[i] = ft_convert(tmp, type);
		d = d / base;
		i--;
	}
	return (str);
}

void	ft_print_no_min(t_flags flags, int len_print, char *str, int slen)
{
	int i;

	i = -1;
	while (++i < flags.width)
	{
		if (*str == '-' && i == flags.width - len_print)
		{
			ft_putchar_fd((*str++), 1);
			slen--;
		}
		else if (*str == '0' && *(str + 1) == 'x'
		&& i > flags.width - len_print - 1 && flags.type == 'p')
		{
			ft_putchar_fd((*(str++)), 1);
			ft_putchar_fd((*(str++)), 1);
			slen -= 2;
			i++;
		}
		else if (i >= flags.width - len_print && i < flags.width - slen)
			ft_putchar_fd('0', 1);
		else if (i >= flags.width - slen)
			ft_putchar_fd((*(str++)), 1);
		else
			ft_putchar_fd(' ', 1);
	}
}

void	ft_print_minus(t_flags flags, int len_to_print, char *str, int strlen)
{
	int i;

	i = 0;
	while (i < flags.width)
	{
		if (*str == '-' && i == 0)
		{
			ft_putchar_fd((*(str++)), 1);
			strlen--;
		}
		else if (*str == '0' && *(str + 1) == 'x' && i == 0)
		{
			ft_putchar_fd((*(str++)), 1);
			ft_putchar_fd((*(str++)), 1);
			strlen -= 2;
			i++;
		}
		else if (i < len_to_print - strlen)
			ft_putchar_fd('0', 1);
		else if (i >= len_to_print - strlen && i < len_to_print)
			ft_putchar_fd((*(str++)), 1);
		else
			ft_putchar_fd(' ', 1);
		i++;
	}
}

void	ft_print_digit(t_flags flags)
{
	int				d;
	int				strlen;
	int				len_to_print;
	char			*str;

	d = 0;
	if (flags.type == 'i' || flags.type == 'd')
	{
		d = va_arg(g_ap, int);
		str = get_string_from_int(flags, d);
	}
	else if (flags.type == 'u')
		str = get_string_from_u(flags);
	else if (flags.type == 'x' || flags.type == 'X')
		str = get_string_from_hex(flags);
	else if (flags.type == 'p')
		str = get_string_from_p(flags);
	else
		str = ft_strdup("");
	g_str_begin = str;
	strlen = ft_strlen(str);
	len_to_print = get_len_to_print(&flags, strlen, d);
	(flags.minus == 0) ? ft_print_no_min(flags, len_to_print, str,
	strlen) : ft_print_minus(flags, len_to_print, str, strlen);
	free(g_str_begin);
}
