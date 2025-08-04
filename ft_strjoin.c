/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:12:36 by aobshatk          #+#    #+#             */
/*   Updated: 2025/08/01 20:53:22 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_gen.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	char	*temp;
	int		len;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	jstr = malloc(sizeof(char) * len + 1);
	if (jstr == NULL)
		return (NULL);
	temp = jstr;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (jstr);
}
