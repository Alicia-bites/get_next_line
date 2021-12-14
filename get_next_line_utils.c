/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:51:46 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/14 16:05:56 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	ft_strlen(char *str)
{
		int	i;

		i = 0;
		while (str[i])
				i++;
		return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*copy;

	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	copy = malloc(sizeof(*copy) * (len + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&s[i]);
}

char	*ft_realloc_and_concat(char *str, size_t oldsize,
			size_t newsize, char *newstr)
{
	size_t	destsize;
	char	*dest;
	size_t	i;
	size_t	j;
	
	if (!str || ! newstr)
			return (0);
	destsize = newsize + oldsize;
	dest = malloc(sizeof(char) * destsize + 1);
	i = 0;
	if (!dest)
		return (0);
	while (i < oldsize)
	{
		dest[i] = str[i];
		i++;
	}
	j = 0;
	while (j < newsize)
	{
		dest[i] = newstr[j];
		i++;
		j++;
	}
	free(str);
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_free(char *str)
{
		free(str);
		return (NULL);
}

/*int main()
{
		char *str = "alicia";
		char *newstr = "PA";
		size_t newsize = 2;
		size_t oldsize = 6;

		printf("%s\n", realloc_and_concat(str, oldsize, newsize, newstr));
		return (0);
}*/
