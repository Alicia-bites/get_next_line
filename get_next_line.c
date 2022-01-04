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

char	*ft_get_leftovers(char *buf, int *remember)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (len < BUFFER_SIZE && buf[len] != '\n')
		len++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (ft_free(line));
	while (i < len && buf[i] != '\n')
	{
		line[i] = buf[*remember];
		i++;
		(*remember)++;
	}
	line[i] = '\0';
	while (remember)
		*remember = len;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			has_read;
	static	int	read_counter = 0;
	static int	remember;
	static int	checkbuf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	checkbuf = 1;
	if 
	if (checkbuf > 0)
	{
		line = ft_get_leftovers(buf, &remember);
		return (line);
	}
	has_read = 0;
	while (has_read)
	{
		has_read = read(fd, buf, BUFFER_SIZE);
		read_counter++;
		printf("read_counter :%d\n", read_counter);
		if (has_read == -1)
			return (NULL);
		buf[has_read] = '\0';
		if (read_counter == 1)
		{
			line = ft_strdup(buf, &remember);
			//printf("remember = %d\n", remember);
			return (line);
		}
		else
		{
			temp = ft_strdup(buf, &remember);
			//printf("temp = %s\n", temp);
			//printf("line = %s\n", line);
			line = ft_realloc_and_concat(line, ft_strlen(line), ft_strlen(temp), temp);
			checkBuf = 0;
			//printf("line after realloc and concat = %s\n\n", line);
			if (has_read == 0)
				return (NULL);
		}
	}
	return (line);
}