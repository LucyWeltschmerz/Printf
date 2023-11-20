/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larzuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:48:38 by larzuman          #+#    #+#             */
/*   Updated: 2021/02/02 16:10:45 by larzuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	int		i;
	int		j;

	if (!s1 || !s2 ||
		!(sjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		sjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		sjoin[i++] = s2[j++];
	sjoin[i] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (sjoin);
}
