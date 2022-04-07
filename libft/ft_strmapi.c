/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:36:31 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/16 15:17:00 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*aux;
	int		i;
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		aux = (char *) malloc(len + 1);
		if (!aux)
			return (0);
		i = 0;
		while (i < len)
		{
			aux[i] = f(i, s[i]);
			i++;
		}
		aux[len] = '\0';
		return (aux);
	}
	return (NULL);
}
