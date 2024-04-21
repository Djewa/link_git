/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djewapat < djewapat@student.42bangkok.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:55:15 by djewapat          #+#    #+#             */
/*   Updated: 2024/04/09 13:04:41 by djewapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int find)
{
	int	i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char)find)
			return ((char *)(str + i));
		i++;
	}
	if ((unsigned char)find == NULL)
		return ((char *)(str + i));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
		str[i++] = s1[i++];
	while (s2[j])
		str[i++] = s2[j++];
	str[len] = '\0';
	// free (s1);
	return (str);
}
