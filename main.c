/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:40:07 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/16 14:14:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
    int		fd;
    char	*line;
    int     i;
	(void)argc;
    i = 1;
    fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)) != NULL && i < 2)
    {
        printf("%s", line);
        i++;
        free(line);
    }
	puts("EOF");
}
