/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djewapat < djewapat@student.42bangkok.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:54:36 by djewapat          #+#    #+#             */
/*   Updated: 2024/05/01 12:34:04 by djewapat         ###   ########.fr       */
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
		len++; //5
	if (buffer[i] == '\n')
		len++; //6
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len) //hello\nworld
	{				//01234 56
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
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
	if (*buffer == '\n')
		i++; //6
	next = (char *)malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (next == NULL)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0') 	//hello\nworld
		next[j++] = buffer[i++];//01234 5678910
	next[j] = '\0';
	if (!*next)
	// if (next[i][j] == '\0')
		return (free(next), free(buffer), NULL);
	free (buffer);
	return (next);
}

// static char	*ft_read_line(int fd, char *buffer)
// {
// 	char	*temp;
// 	int		read_byte;

// 	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (temp == NULL)
// 		return (NULL);
// 	read_byte = 1;
// 	while (read_byte != 0 && ft_strchr(buffer, '\n') == NULL)
// 	{
// 		read_byte = read(fd, buffer, BUFFER_SIZE);
// 		if (read_byte == -1)
// 		{
// 			free (buffer);
// 			free (temp);
// 			return (NULL);
// 		}
// 		temp[read_byte] = '\0';
// 		buffer = ft_strjoin(buffer, temp);
// 	}
// 	free (temp);
// 	return (buffer);
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	read_byte = 1;
	while (read_byte != 0 && (!ft_strchr(buffer, '\n')))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free (buffer);
			free (line);
			return (NULL);
		}
		line[read_byte] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	//buffer = ft_read_line(fd, buffer);
	free (line);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}

#include <fcntl.h>

int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *line;
	int no = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("%i: %s", no, line);
		free(line);
		line = get_next_line(fd);
		no++;
	}
	close(fd);
	return (0);
}