/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luprevos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:54:29 by luprevos          #+#    #+#             */
/*   Updated: 2024/10/22 15:01:20 by luprevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		printf("Line is: \"%s\"\n\n", line);
		free(line);
		i++;
	}
}
