/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:11:21 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 00:17:43 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_ln(char *str, int fd)
{
	char	*buffer;
	int		i;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ftstrchr (str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(str);
			str = NULL;
			return (NULL);
		}
		buffer[i] = '\0';
		str = ftjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*chyataline(char *st)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (st[i] != '\n' && st[i] != '\0')
		i++;
	if (ft_strlen(st) == i)
	{
		free(st);
		return (NULL);
	}
	line = (char *)malloc((ft_strlen(st) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (st[i++])
	{
		line[j] = st[i];
		j++;
	}
	line[j] = '\0';
	free(st);
	return (line);
}

char	*ftstrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	ftjoin2(char *char1, char *char2, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (char1[i] != '\0')
	{
		str[i] = char1[i];
		i++;
	}
	while (char2[j])
	{
		str[i] = char2[j];
		i++;
		j++;
	}
	str[ft_strlen(char1) + ft_strlen(char2)] = '\0';
	free(char1);
}

char	*ftjoin(char *char1, char *char2)
{
	char	*str;

	if (!char1)
	{
		char1 = (char *)malloc(sizeof(char));
		if (!char1)
			return (NULL);
		char1[0] = '\0';
	}
	if (!char2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(char1) + ft_strlen(char2)) + 1));
	if (!str)
		return (NULL);
	ftjoin2(char1, char2, str);
	return (str);
}
