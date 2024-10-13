/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:59:05 by luprevos          #+#    #+#             */
/*   Updated: 2024/09/29 23:41:44 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *c);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
int		ft_free(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_split(char *tab, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *str, char *s2, char c);
char	*get_next_line(int fd);

#endif
