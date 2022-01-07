// #include "get_next_line.h"

// char	*ft_strdup(char *src, int *remember)
// {
// 	int		i;
// 	int		len;
// 	char	*copy;

// 	len = 0;
// 	if (!src)
// 		return (NULL);
// 	while (len < 10 && src[len - 1] != '\n')
// 		len++;
//     printf("len = %d\n", len);
// 	copy = malloc(sizeof(char) * (len + 1));
// 	if (!copy)
// 		return (NULL);
// 	i = 0;
// 	while (i < len && src[i - 1] != '\n')
// 	{
// 		copy[i] = src[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
//     if (remember >= 10)
//         *remember = 0;
// 	else if (remember != NULL)
// 		*remember = len;
//     printf("remember : %d\n", *remember);
// 	return (copy);
// }

// int main(void)
// {
//     char *buf = "lechatmang";
// 	int rem = 0;
// 	int	*remember;

// 	remember = &rem;
//     printf("%s\n", ft_strdup(buf, remember));
//     return (0);
// }