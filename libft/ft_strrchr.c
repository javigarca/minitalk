/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:08:59 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/10 20:49:49 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*aux;
	char	tofind;

	i = 0;
	tofind = (char) c;
	aux = (char *) str;
	while (aux[i] != 00)
		i++;
	while (i > 0)
	{
		if (aux[i] == tofind)
			return (&aux[i]);
		i--;
	}
	if (aux[i] == tofind)
		return (&aux[i]);
	return (0);
}
