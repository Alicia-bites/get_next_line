// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/13 14:52:03 by amarchan          #+#    #+#             */
// /*   Updated: 2021/12/16 14:18:32 by amarchan         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// int	ft_check_remember(int remember)
// {
// 	if (remember >= BUFFER_SIZE)
// 		remember = 0;
// 	else
// 		remember += 1;
// 	return (remember);
// }

// char	*ft_get_leftovers(char *buf, int *remember)
// {
// 	int		i;
// 	int		len;
// 	char	*line;
	
// 	len = *remember;
// 	while (len < BUFFER_SIZE && buf[len] != '\n')
// 		len++;
// 	len -= (*remember);
// 	line = malloc(sizeof(char) * (len + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (i < (len + 1) && buf[*remember] != '\n')
// 	{
// 		line[i] = buf[*remember];
// 		i++;
// 		(*remember)++;
// 	}
// 	if (buf[*remember] == '\n')
// 		line[i++] = '\n';
// 	line[i++] = '\0';
// 	*remember = ft_check_remember(*remember);
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	char		*line;
// 	char		*temp;
// 	int			has_read;
// 	static	int	read_counter = 0;
// 	static int	remember = 0;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || remember < 0)
// 		return (NULL);
// 	if (remember > 0)
// 	{
// 		//printf("remember : %d\n", remember);
// 		line = ft_get_leftovers(buf, &remember);
// 		//printf("line : %s\n", line);
// 		if (ft_strchr(line, '\n') >= 0)
// 			return (line);
// 	}
// 	has_read = BUFFER_SIZE;
// 	while (has_read == BUFFER_SIZE && ft_strchr(line, '\n') < 0)
// 	{
// 		has_read = read(fd, buf, BUFFER_SIZE);
// 		read_counter++;
// 		//printf("read_counter :%d\n", read_counter);
// 		if (has_read == -1 || has_read == 0)
// 			return (NULL);
// 		buf[has_read] = '\0';
// 		if (read_counter == 1)
// 		{
// 			line = ft_strdup(buf, &remember);
// 			//printf("remember = %d\n", remember);
// 			return (line);
// 		}
// 		else
// 		{
// 			temp = ft_strdup(buf, &remember);
// 			//printf("temp = %s\n", temp);
// 			//printf("line = %s\n", line);
// 			line = ft_realloc_and_concat(line, ft_strlen(line), ft_strlen(temp), temp);
// 			//printf("line after realloc and concat = %s\n", line);
// 		}
// 	}
// 	return (line);
// }