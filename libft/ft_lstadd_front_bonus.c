/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:17:38 by subpark           #+#    #+#             */
/*   Updated: 2023/06/02 11:13:24 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int main()
{
	t_list *lst = ft_lstnew((const char *)"hello");
	t_list *new = ft_lstnew((const char *)"what happened ");
	t_list *curr;
	ft_lstadd_front(&lst, new);
	curr = new;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	free (lst);
	free (new);
	return (0);
}*/