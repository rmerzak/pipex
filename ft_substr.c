/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:31:46 by rmerzak           #+#    #+#             */
/*   Updated: 2022/01/02 19:41:38 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	k;

	k = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		p = (char *)malloc(sizeof(char));
		p[0] = '\0';
		return (p);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (k < len)
	{
		p[k] = s[start + k];
		k++;
	}
	p[k] = '\0';
	return (p);
}
