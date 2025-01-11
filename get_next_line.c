/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:25:34 by pteixeir          #+#    #+#             */
/*   Updated: 2025/01/10 23:21:29 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_extract_line(char *stash);
char *ft_adjust_stash(char *stash);
char *ft_read_to_stash(char *stash, int fd);

char *get_next_line(int fd)
{
    static char *stash;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = ft_read_to_stash(stash, fd);
    if (!stash)
    {
        free(stash);
        return (NULL);
    }
    line = ft_extract_line(stash);
    stash = ft_adjust_stash(stash);
    return (line);
}

char *ft_read_to_stash(char *stash, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_char_in_str(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (stash)
				free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char *ft_extract_line(char *stash)
{
    char    *line;
    int i;
    int j;
    
    if (!stash)
        return (NULL);
    i = 0;
    while (stash[i] != '\n' && stash[i])
        i++;
    line = ft_calloc(j + 1, sizeof(char));
    if (!line)
        return (NULL);
   ft_strcpy_gnl(stash, line,1);
    return (line);    
}

char *ft_adjust_stash(char *stash)
{
    char    *new_stash;
    int index;

    index = 0;
    while (stash[index] && stash[index] != '\n')
        index++;
    if (stash[index] == '\0')
    {
        free(stash);
        return (NULL);
    }
    index++;
    new_stash = ft_calloc(ft_strlen_gnl(stash + index) + 1, sizeof(char));
    if (!new_stash)
        return (NULL);
    ft_strcpy_gnl(stash + index, new_stash, 0);
    free(stash);
    return (new_stash);
}
