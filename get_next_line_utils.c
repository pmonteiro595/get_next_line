/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:39:35 by pteixeir          #+#    #+#             */
/*   Updated: 2025/01/08 22:36:58 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*str_mlc;
	size_t	size_of_s;
	size_t	i;

	i = 0;
	size_of_s = ft_strlen(s);
	str_mlc = malloc(sizeof(char) * (size_of_s + 1));
	if (str_mlc == NULL)
		return (NULL);
	while (i < size_of_s)
	{
		str_mlc[i] = s[i];
		i++;
	}
    str_mlc[i] = '\0';
	return (str_mlc);
}

char *ft_strchr(const char *s, int c)
{
    int i;
    
    i = 0;
    
    if (!s)
        return (NULL);
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *new_str;
    size_t  i;
    size_t  j;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
    return (ft_strdup(s2));
    if (!s2)
    return (ft_strdup(s1));
    new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new_str)
        return(NULL);
    i = 0;
    while (s1[i])
    {
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        new_str[i + j] = s2[j];
        j++;
    }
    new_str[i + j] = '\0';
    return (new_str);
}

char *extract_line(char *stash)
{
    char    *line;
    int i;
    
    if (!stash)
        return (NULL);
    i = 0;
    while (stash[i])
        i++;
    line = malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i])
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);    
}

char *adjust_stash(char *stash)
{
    char    *new_stash;
    int i;
    int j;

    if (!stash)
        return (NULL);

    i = 0;
    while (stash[i])
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i));
    if  (!new_stash)
        return(NULL);
    i++;
    j = 0; 
    while (stash[i])
    {
        new_stash[j] = new_stash[i];
        i++;
        j++;
    }
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}
