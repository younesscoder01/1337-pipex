/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:20:19 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/23 14:01:36 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_it_in(const char *str, char c)
{
	while (*str && c != *str)
		str++;
	return (c == *str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	last;
	size_t	first;

	if (!s1 || !set)
		return (0);
	first = 0;
	last = ft_strlen(s1);
	while (is_it_in(set, s1[first]) && s1[first])
		first++;
	if (first == last)
		return (ft_strdup(""));
	while (is_it_in(set, s1[last - 1]))
		last--;
	return (ft_substr(s1, first, last - first));
}
