/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:18:38 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/18 14:28:53 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	rtrn;

	i = 0;
	rtrn = 0;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != 00))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 00;
	}
	while (src[rtrn] != 00)
		rtrn++;
	return (rtrn);
}
