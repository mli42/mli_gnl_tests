/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:55:01 by mli               #+#    #+#             */
/*   Updated: 2019/11/11 14:32:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		gnl_r;
	int		fd = -1;
	int		i = 1;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd >= 0)
	{
		while ((gnl_r = get_next_line(fd, &line)) == 1)
		{
			printf("RETURNED[%d][%d]:%s\n", gnl_r, i++, line);
			free(line);
		}
		if (gnl_r == 0)
		{
			printf("RETURNED[%d][%d]:%s\n", gnl_r, i, line);
			free(line);
		}
		else if (gnl_r == -1)
		{
			printf("RETURNED[%d][%d]:\tHAD AN ERROR || STOP\n", gnl_r, i);
			free(line);
		}
		close(fd);
	}
	printf("\nBoucle inf, leaks ?\n");
	while (1);
	return (0);
}
