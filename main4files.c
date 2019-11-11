/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:26:57 by mli               #+#    #+#             */
/*   Updated: 2019/11/12 00:17:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int		fd_open(int	*fd, int size)
{
	int i = 0;

	while (i < size)
		if (fd[i++] == 1)
			return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd[10];
	int		fd_read[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int		max = argc - 1;
	int 	i = -1;
	int		j = 1;

	if (argc > 1)
		while (++i < max)
			fd[i] = open(argv[i + 1], O_RDONLY);
	i = 0;
	while (fd_open(fd_read, max))
	{
		if (fd_read[i % (max)])
		{
			fd_read[i % (max)] = get_next_line(fd[i % max], &line);
			printf("RETURNED[FILE:%d][%d][%d]:%s\n", i % max, fd_read[i % max], j++, line);
			free(line);
		}
		i++;
	}
	i = -1;
	if (argc > 1)
		while (++i < max)
			close(fd[i]);
	//	printf("\nBoucle inf, leaks ?\n");
	//	while (1);
	return (0);
}
