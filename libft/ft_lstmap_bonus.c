/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:53:12 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/29 14:03:06 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*ptr;

	if (!f || !lst || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		temp = ft_lstnew(ptr);
		if (!temp)
		{
			ft_lstclear(&new, (*del));
			free(ptr);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
