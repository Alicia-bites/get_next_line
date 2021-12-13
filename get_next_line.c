/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:52:03 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/13 21:15:53 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_do_the_reading()
{

char	*get_next_line(int fd);
{
	char	buf[BUFFER_SIZE];
	int		has_read;
	static 	i;
	char	*dest;
	char 	*newbuf;
	
	i = 0;
	while (has_read <= 0)
	{
		has_read = read(fd, buf, BUFFER_SIZE);
		if (has_read == -1)
			return (0);
		while (buf[i])
		{
			if (buf[i] == '\n' || buf[i] == '\0')
			{
				newbuf = ft_strdup(buf);
				dest = ft_realloc(buf, ft_strlen(buf), ft_strlen(newbuf),
					new buf);
			}
			i++;
		}
	}
	return (dest)
}
