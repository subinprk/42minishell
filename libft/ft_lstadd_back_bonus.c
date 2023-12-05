/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:38:47 by subpark           #+#    #+#             */
/*   Updated: 2023/06/02 11:09:45 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

/*
#include <stdio.h>
int main()
{
	t_list *lst1 = NULL;
	t_list  *lst2 = ft_lstnew((const char *)"hello");
	t_list *new = ft_lstnew((const char *)"what happened ");
	t_list *curr;
	ft_lstadd_back(&lst1, lst2);
	ft_lstadd_back(&lst1, new);
	curr = lst1;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	free (lst1);
	free(lst2);
	free (new);
	return (0);
}*/