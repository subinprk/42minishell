/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:22:27 by subpark           #+#    #+#             */
/*   Updated: 2023/06/02 11:00:57 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		index;

	curr = lst;
	index = 0;
	if (lst == NULL)
		return (0);
	while (curr->next != NULL)
	{
		index ++;
		curr = curr->next;
	}
	return (index + 1);
}
/*
#include <stdio.h>
int main()
{
	t_list *lst1 = ft_lstnew((const char *)"hello");
	t_list *lst2 = ft_lstnew((const char *)"what happened ");
	t_list *lst3 = ft_lstnew((const char *)"Nothing ");
	t_list *curr;
	(*lst1).next = lst2;
	(*lst2).next = lst3;
	curr = lst1;
	while (curr != NULL)
	{
		printf("%s \n", curr->content);
		curr = curr->next;
	}
	printf("%d",ft_lstsize(lst1));
	free (lst1);
	free (lst2);
	free (lst3);
	return (0);
}
*/