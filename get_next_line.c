/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:12:37 by luprevos          #+#    #+#             */
/*   Updated: 2024/10/14 17:04:07 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_split(char *tab, char c)
{
	int		i;
	int		chr;
	char	*str;

	i = 0;
	chr = 0;
	if (ft_strchr(tab, c) == NULL)
		return (tab);
	while (tab[chr] != c)
		chr++;
	str = malloc(sizeof(char) * (chr + 2));
	if (!str)
		return (NULL);
	while (i < chr + 1)
	{
		str[i] = tab[i];
		i++;
	}
	str[i] = '\0';
	free(tab);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	len;

	i = -1;
	j = -1;
	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) + (len + 1));
	ft_bzero(str, len + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	free(s1);
	return (str);
}

char	*ft_strncpy(char *str, char *s2, char c)
{
	int	i;
	int	chr;

	i = 0;
	chr = 0;
	while (s2[chr] && s2[chr] != c)
		chr++;
	if (ft_strlen(s2) == chr)
		return (NULL);
	chr++;
	while (s2[chr])
	{
		str[i] = s2[chr];
		chr++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_ligne(char *line, int fd)
{
	char	read_in[BUFFER_SIZE + 1];
	int		srch_read;

	while (ft_strchr(line, '\n') == NULL)
	{
		srch_read = read(fd, read_in, BUFFER_SIZE);
		if (srch_read == 0)
			break ;
		if (srch_read < 0)
		{
			free(line);
			return (NULL);
		}
		read_in[srch_read] = '\0';
		line = (ft_strjoin(line, read_in));
		if (!line)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*ligne;
	static char	apres_n[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_bzero(apres_n, BUFFER_SIZE + 1);
	ligne = ft_strdup(apres_n);
	ligne = ft_ligne(ligne, fd);
	if (ligne == NULL)
		return (NULL);
	ft_strncpy(apres_n, ligne, '\n');
	ligne = ft_split(ligne, '\n');
	if (ft_strlen(ligne) == 0)
	{
		free(ligne);
		return (NULL);
	}
	return (ligne);
}

// int 	main(void)
// {
// 	int fd;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		char *line = get_next_line(fd);
// 		printf("Line is: %s ...\n\n", line);
// 		printf("Pointer of: %p.../n/n", line);
// 		free(line);
// 		i++;
// 	}
// }
