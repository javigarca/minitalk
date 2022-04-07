/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:09:51 by javigarc          #+#    #+#             */
/*   Updated: 2021/10/20 19:27:45 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_sz;
	size_t	s_sz;

	d_sz = 0;
	s_sz = 0;
	while (dest[d_sz] != 00)
		d_sz++;
	while (src[s_sz] != 00)
		s_sz++;
	i = d_sz;
	j = 0;
	if (size < 1)
		return (s_sz + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < d_sz)
		return (s_sz + size);
	return (d_sz + s_sz);
}
