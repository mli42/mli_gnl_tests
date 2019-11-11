/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:26:57 by mli               #+#    #+#             */
/*   Updated: 2019/11/11 14:27:02 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd[2];
	int		fd_open[2];
	int		fd_read[2];
	int 	i = 0;
	int		j = 1;

	fd_open[0] = 1; fd_open[1] = 1;
	if (argc == 3)
		if ((fd[0] = open(argv[1], O_RDONLY)) && (fd[1] = open(argv[2], O_RDONLY)))
		{
			while (fd_open[0] || fd_open[1])
			{
				if (fd_open[i % 2])
				{
					fd_open[i % 2] = ((fd_read[i % 2] = get_next_line(fd[i % 2], &line)) == 1);
					printf("RETURNED[FILE:%d][%d][%d]:%s\n", i % 2, fd_read[i % 2], j++, line);
					free(line);
				}
				i++;
			}
			close(fd[0]);
			close(fd[1]);
		}
	printf("\nBoucle inf, leaks ?\n");
	while (1);
	return (0);
}
