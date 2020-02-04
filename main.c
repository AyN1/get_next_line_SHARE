/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abicer <abicer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:12:13 by abicer            #+#    #+#             */
/*   Updated: 2020/02/04 15:38:58 by abicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*ligne;
	int		ret;

	ligne = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 1 || argc > 2)
	{
		printf("usage: ./a.out text.txt\n");
		return (0);
	}

	// int nbr_exec = 0;
	// while (nbr_exec < 1)
	// {
	// 	ret = get_next_line(fd, &ligne); //
	// 	printf("[%d] ", ret);
	// 	printf("%s\n", ligne);
	// 	++nbr_exec;
	// }

	while ((ret = get_next_line(fd, &ligne)) >= -1)
	{
		printf("[%d] ", ret);
		printf("%s\n", ligne);
		free(ligne);
		ligne = NULL;
		if (ret == 0)
			break ;
		if (ret == -1)
			break ;
	}
	return (0);
}