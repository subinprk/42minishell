/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:52:22 by subpark           #+#    #+#             */
/*   Updated: 2023/06/02 11:11:00 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
	f(tmp->content);
}
/*
void    tmpprint(void *content)
{
	printf("%s\n", content);
	return ;
}

void    tmpdel(void *content)
{
	printf("deleted\n");
	return ;
}

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
	ft_lstiter(lst1, tmpprint);
	ft_lstclear(&lst1, tmpdel);
	return (0);
}*/