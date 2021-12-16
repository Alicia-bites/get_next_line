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
		char			buf[BUFFER_SIZE + 1];
		char			*remember;
		char			*temp;
		int				has_read;
		static	int		read_counter;
		int				i;

		if (fd < 0 || BUFFER_SIZE <= 0)
				return (NULL);
		i = 0;
		while (i < BUFFER_SIZE)
		{
				buf[i] = 0;
				i++;
		}
		has_read = 1;
		read_counter = 0;
		while (has_read <= BUFFER_SIZE && strchr(buf, '\n') == NULL) 
		{
				has_read = read(fd, buf, BUFFER_SIZE);
				read_counter++;
				if (has_read == -1)
						return (ft_free(buf));
				buf[has_read] = '\0';
				if (read_counter == 1)
						remember = ft_strdup(buf);
				else
				{
						temp = ft_strdup(buf);
						remember = ft_realloc_and_concat(remember, ft_strlen(remember), ft_strlen(temp), temp);
						if (has_read == 0)
						{
								ft_free(remember);
								return (NULL);
						}
				}
		}
		return (remember);
}
