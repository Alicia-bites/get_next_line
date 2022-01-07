
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
// 	while (len < 12 && buf[len] != '\n')
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
// 	printf("remember = %d\n", *remember);
// 	return (line);
// }

// int main(void)
// {
//     char *buf = "le\nchat\nmang";
// 	int rem = 8;
// 	int	*remember;

// 	remember = &rem;
//     printf("%s", ft_get_leftovers(buf, remember));
//     return (0);
// }