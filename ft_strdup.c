/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:20:08 by larzuman          #+#    #+#             */
/*   Updated: 2021/02/02 15:33:03 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	void	*new;

	length = ft_strlen(s1) + 1;
	new = malloc(length);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s1, length));
}
