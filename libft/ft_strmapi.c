/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:49:12 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/29 14:07:53 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		slen;
	int		index;
	char	*str;

	if (!s || !f)
		return (NULL);
	index = 0;
	slen = ft_strlen(s);
	str = malloc(sizeof(char) * slen + 1);
	if (!str)
		return (NULL);
	while (index < slen)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
