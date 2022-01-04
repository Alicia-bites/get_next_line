/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:52:03 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/16 14:18:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			has_read;
	static	int	read_counter = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (buf[j] != '\0')
	{
		line = strdup(line)
	}
	has_read = 0;
	while (has_read <= BUFFER_SIZE || ft_strchr(buf, '\n') <= 0)
	{
		has_read = read(fd, buf, BUFFER_SIZE);
		read_counter++;
		//printf("read_counter :%d\n", read_counter);
		if (has_read == -1)
			return (NULL);
		buf[has_read] = '\0';
		if (read_counter == 1)
		{
			line = ft_strdup(buf);
			return (line);
		}
		else
		{
			temp = ft_strdup(buf);
			//printf("temp = %s\n", temp);
			//printf("line = %s\n", line);
			line = ft_realloc_and_concat(line, ft_strlen(line), ft_strlen(temp), temp);
			printf("line after realloc and concat = %s\n\n", line);
			if (has_read == 0)
			{
				ft_free(line);
				return (NULL);
			}
		}
	}
	return (line);
}