/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:47:24 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 00:23:17 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	i++;
// 	return (i);
// }

char	*linegadgad(char *str)
{
	char	*lin;
	int		i;
	int		j;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	lin = (char *)malloc(sizeof(char) * i + 1);
	if (lin == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		lin[j] = str[j];
		j++;
	}
	lin[j] = '\0';
	return (lin);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = read_ln(s, fd);
	if (s == NULL)
		return (NULL);
	buf = linegadgad(s);
	s = chyataline(s);
	return (buf);
}
