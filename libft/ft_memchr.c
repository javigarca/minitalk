/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:29:19 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/18 17:34:57 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*swap;

	swap = (unsigned char *) s;
	i = 0;
	if (n == 0)
		return (NULL);
	while ((swap) && (n > (i + 1)))
	{
		if (swap[i] == (unsigned char) c)
			return ((void *)&swap[i]);
		i++;
	}
	if (swap[i] == (unsigned char) c)
		return ((void *)&swap[i]);
	return (NULL);
}
