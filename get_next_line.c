/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djewapat < djewapat@student.42bangkok.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:54:36 by djewapat          #+#    #+#             */
/*   Updated: 2024/05/01 11:34:22 by djewapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *buffer)
{
	char	*str;
	int		len;
	int		i;

	if (buffer == NULL)
		return (NULL);
	len = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		len++;
	while (buffer[i] == '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = buffer[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

static char	*ft_next_line(char *buffer)
{
	size_t		i;
	size_t		j;
	char		*next;

	if (buffer == NULL)
	{
		free (buffer);
		return (NULL);
	}
	i = 0;
	while ((*buffer != '\n') && (*buffer != '\0'))
		i++;
	while (*buffer == '\n')
		i++;
	next = (char *)malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (next == NULL)
		return (NULL);
	j = 0;
	while (*buffer != '\0')
		next[j++] = buffer[i++];
	next[j] = '\0';
	if (!*buffer)
		return (free(next), free(buffer), NULL);
	free (buffer);
	return (next);
}

static char	*ft_read_line(int fd, char *buffer)
{
	char	*temp;
	int		read_byte;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	read_byte = 1;
	while (read_byte != 0 && ft_strchr(buffer, '\n') == NULL)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (buffer);
			free (temp);
			return (NULL);
		}
		temp[read_byte] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

#include <fcntl.h>

int	main()
{
	int	fd;

	fd = open("a.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}