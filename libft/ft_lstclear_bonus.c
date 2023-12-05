/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:38:55 by subpark           #+#    #+#             */
/*   Updated: 2023/06/02 12:05:46 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmpfree;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		tmpfree = tmp;
		tmp = tmp->next;
		del(tmpfree->content);
		free(tmpfree);
	}
	*lst = NULL;
}
/*
void    tmpdel(void *content)
{
	printf("deleted\n");
	return ;
}*/
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
	printf("%d\n",ft_lstsize(lst1));
	printf("%p\n",ft_lstlast(lst1));
	printf("%p\n", lst3);
	ft_lstclear(&lst1, tmpdel);
	return (0);
}*/