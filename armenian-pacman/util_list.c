/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:04:25 by amkrtumy          #+#    #+#             */
/*   Updated: 2023/02/17 18:16:32 by amkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	lst_ = ft_lstlast(*lst);
	lst_->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (!(*lst))
		return ;
	while (temp != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = temp;
	}
	lst = NULL;
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
	lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

t_list	*ft_lstnew(t_key_value content)
{
	t_list	*target;

	target = (t_list *)malloc(sizeof(t_list));
	if (!target)
		return (NULL);
	(*target).content = content;
	target->next = NULL;
	return (target);
}
