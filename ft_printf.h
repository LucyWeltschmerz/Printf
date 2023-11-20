/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:50:41 by larzuman          #+#    #+#             */
/*   Updated: 2021/04/26 14:50:44 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

va_list			g_ap;
int				g_char_count;
char			*g_str;
char			*g_str_begin;

typedef	struct	s_flags
{
	int minus;
	int zero;
	int dot;
	int	width;
	int	prec;
	int	type;

}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_print_str(char *s, t_flags flags);
void			ft_putnbr_fd(long n, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strlen(const	char *str);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *dst, const void *src, size_t length);
void			ft_print_char(t_flags flags);
void			ft_print_digit(t_flags flags);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_get_num(void);
void			treat_minus_flag(t_flags *flags);
void			treat_zero_flag(t_flags *flags);
void			treat_asterix_flag(t_flags *flags);
void			treat_dot_flag(t_flags *flags);
char			*get_string_from_int(t_flags flags, int d);
char			*get_string_from_u(t_flags flags);
char			*get_string_from_hex(t_flags flags);
char			*get_string_from_p(t_flags flags);
int				get_len_to_print(t_flags *flags, int strlen, int d);
char			*ft_itoa_base(uintmax_t d, int base, char type);

#endif
