/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:52:03 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/14 17:06:21 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	char		*line_returned;	
	char		*newbuf;
	static int	has_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	has_read = 1;
	newbuf = NULL;
	/*tant que je ne suis pas arrive a EOF et que je ne rencontre par de \n*/
	while (has_read >= 0)             
	{
		has_read = read(fd, buf, BUFFER_SIZE);
		if (has_read == -1)
			return (ft_free(buf));
		
	}
	newbuf = buf;
	line_returned = ft_realloc_and_concat(buf, ft_strlen(buf),
		ft_strlen(newbuf));
	line_returned[has_read] = '\0';
	printf("line_returned : %s\n", line_returned); 
	return (line_returned);
}
