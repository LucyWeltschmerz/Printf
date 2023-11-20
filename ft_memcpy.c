/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:15:11 by larzuman          #+#    #+#             */
/*   Updated: 2021/02/03 20:02:18 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t length)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			index;

	if (dst == NULL && src == NULL)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	index = 0;
	while (index < length)
	{
		cdst[index] = csrc[index];
		++index;
	}
	return (dst);
}
