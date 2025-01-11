/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pteixeir <pteixeir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:33:07 by pteixeir          #+#    #+#             */
/*   Updated: 2025/01/10 23:35:07 by pteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
char    *ft_adjust_stash(char *stash);
char    *ft_extract_line(char *stash);
char    *ft_read_to_stash(char *stash, int fd);
char    *ft_strjoin_gnl(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int ft_check_chars(char *str, int c);
size_t  ft_strlen_gnl(const char *s);

#endif
