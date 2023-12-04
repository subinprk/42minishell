/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siun <siun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:56:35 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/04 21:46:08 by siun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*allocates memory for a string ad sets all its bytes to '\0'*/
char    *ft_strnew(size_t size)
{
    char    *str;
    size_t    i;

    i = 0;
    str = (char *)malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    while (i < size)
    {
        str[i] = '\0';
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *get_env_value(char *key, char **envs)
{
    int        i;
    char    *value;

    i = 0;
    value = NULL;
    while (envs[i])
    {
        if (ft_strncmp(envs[i], key, ft_strlen(key)) == 0)
        {
            value = ft_strdup(envs[i] + ft_strlen(key) + 1);
            break ;
        }
        i++;
    }
    return (value);
}

int print_error(char *token, char *message)
{
    ft_putstr_fd("minishell: ", 2);
    ft_putstr_fd(token, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(message, 2);
    ft_putstr_fd("\n", 2);
    return (-1);
}

int print_error2(char *token, char *token2, char *message)
{
    ft_putstr_fd("minishell: ", 2);
    ft_putstr_fd(token, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(token2, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(message, 2);
    return (-1);
}

int print_id_error(char *token, char *message)
{
    ft_putstr_fd("minishell: ", 2);
    ft_putstr_fd(token, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(message, 2);
    ft_putstr_fd("': not a valid identifier\n", 2);
}