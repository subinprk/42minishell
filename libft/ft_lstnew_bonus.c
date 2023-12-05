/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:36:10 by subpark           #+#    #+#             */
/*   Updated: 2023/06/02 11:01:31 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}
/*
#include <stdio.h>
int main(){
	t_list *tester = ft_lstnew((char *)"Hello");
	printf("%s", tester->content);
	free (tester);
	return (0);
}*/