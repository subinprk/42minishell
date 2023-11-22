/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:11:29 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/09 16:58:31 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_wstr(int fd, char *wstr)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(wstr, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(wstr);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		wstr = ft_strjoin_frees1(wstr, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (wstr);
}

char	*get_wbuffer(char *wstr)
{
	char	*wbuffer;
	int		i;

	i = 0;
	if (!wstr[i])
		return (NULL);
	while (wstr[i])
		i++;
	wbuffer = malloc(sizeof(char) * (i + 1));
	if (!wbuffer)
		return (NULL);
	i = 0;
	while (wstr[i] && wstr[i] != '\n')
	{
		wbuffer[i] = wstr[i];
		i++;
	}
	if (wstr[i] && wstr[i] == '\n')
	{
		wbuffer[i] = wstr[i];
		i++;
	}
	wbuffer[i] = '\0';
	return (wbuffer);
}

char	*get_strrst(char *wstr)
{
	char	*strrst;
	int		i;
	int		a;

	i = 0;
	while (wstr[i] && wstr[i] != '\n')
		i++;
	if (!wstr[i])
	{
		strrst = NULL;
		free(wstr);
		return (NULL);
	}
	strrst = (char *)malloc(sizeof(char) * (ft_strlen_gnl(wstr) - i + 1));
	if (!strrst)
		return (NULL);
	i++;
	a = 0;
	while (wstr[i])
		strrst[a++] = wstr[i++];
	strrst[a] = '\0';
	free(wstr);
	return (strrst);
}

char	*get_next_line(int fd)
{
	char		*wbuffer;
	static char	*wstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if ((wstr && !ft_strchr_gnl(wstr, '\n')) || !wstr)
		wstr = get_wstr(fd, wstr);
	if (!wstr)
	{
		wstr = NULL;
		return (NULL);
	}
	wbuffer = get_wbuffer(wstr);
	if (!wbuffer)
	{
		free(wstr);
		wstr = NULL;
		wbuffer = NULL;
		return (NULL);
	}
	wstr = get_strrst(wstr);
	if (!wstr)
		free(wstr);
	return (wbuffer);
}
