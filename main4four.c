/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:26:57 by mli               #+#    #+#             */
/*   Updated: 2019/11/11 15:18:48 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd[4];
	int		fd_open[4];
	int		fd_read[4];
	int 	i = 0;
	int		j = 1;

	fd_open[0] = 1; fd_open[1] = 1;
	fd_open[2] = 1; fd_open[3] = 1;
	if (argc == 5)
		if ((fd[0] = open(argv[1], O_RDONLY)) && (fd[1] = open(argv[2], O_RDONLY)) &&
			(fd[2] = open(argv[3], O_RDONLY)) && (fd[3] = open(argv[4], O_RDONLY)))
		{
			while (fd_open[0] || fd_open[1] || fd_open[2] || fd_open[3])
			{
				if (fd_open[i % 4])
				{
					fd_open[i % 4] = ((fd_read[i % 4] = get_next_line(fd[i % 4], &line)) == 1);
					printf("RETURNED[FILE:%d][%d][%d]:%s\n", i % 4, fd_read[i % 4], j++, line);
					free(line);
				}
				i++;
			}
			close(fd[0]);
			close(fd[1]);
			close(fd[2]);
			close(fd[3]);
		}
	printf("\nBoucle inf, leaks ?\n");
	while (1);
	return (0);
}
