/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:20:43 by javigarc          #+#    #+#             */
/*   Updated: 2021/11/02 16:08:13 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (*needle == 00)
		return (haystack);
	while ((haystack[i] != 00) && (len > i))
	{
		k = 0;
		while (haystack[i + k] == needle[k])
		{
			k++;
			if ((needle[k] == 00) && ((i + k) <= len))
				return (&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
