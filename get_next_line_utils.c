/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:39:35 by pteixeir          #+#    #+#             */
/*   Updated: 2025/01/10 23:38:55 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			total_size;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_check_chars(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strcpy_gnl(char *src, char *dest, int gnl_stop)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		if (gnl_stop && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t ft_strlen_gnl(const char *s)
{
    size_t i;
    
    i = 0;
    if (!s)
        return (0);
    while (s && s[i])
        i++;
    return (i);
}

char *ft_strjoin_gnl(char *s1, char *s2)
{
    char    *new_str;
    size_t  len1 = 0, len2 = 0, i = 0, j = 0;
	
	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}
