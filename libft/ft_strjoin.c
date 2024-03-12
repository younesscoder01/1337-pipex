/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:17:34 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/12 15:12:08 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = malloc((lens1 + lens2) * sizeof(char) + 1);
	if (!newstr)
		return (NULL);
	while (*s1)
		*newstr++ = *s1++;
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (newstr - (lens1 + lens2));
}
