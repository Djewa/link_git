/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djewapat < djewapat@student.42bangkok.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:55:38 by djewapat          #+#    #+#             */
/*   Updated: 2024/05/01 12:30:22 by djewapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int find);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif