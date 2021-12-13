/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:52:03 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/13 21:46:03 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd);
{
	char		buf[BUFFER_SIZE];
	int			has_read;
	char		*dest;
	char 		*newline;
	static char *line;
	
	has_read = 1;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	while (&& has_read)
	{
		has_read = read(fd, buf, BUFFER_SIZE);
		if (has_read == -1)
			return (ft_free(buffer));
		line = buf;
		if (ft_strchr(line, '\n') > 0)
		{
			newline = ft_strdup(buf);
			dest = ft_realloc(buf, ft_strlen(buf), ft_strlen(newbuf),
				new buf);
		}
	}
	dest[has_read] = '\0';
	return (dest);
}
