/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:25:34 by pteixeir          #+#    #+#             */
/*   Updated: 2025/01/08 22:13:09 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash = NULL;
    char    buffer[BUFFER_SIZE + 1];
    char    *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = '\0';
        if (stash)
            stash = ft_strjoin(stash, buffer);
        else
            stash = ft_strdup(buffer);
        if (!stash)
            return (NULL);
    }
    line = extract_line(stash);
    stash = adjust_stash(stash);
    return (line);
}
