/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:57:34 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 18:12:36 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x(const char *map)
{
	int		fd;
	int		x;
	char	*str;

	x = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		x++;
	}
	close(fd);
	return (x);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char )s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s = malloc(len * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len);
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	rc;
	size_t	i;

	rc = 0;
	i = 0;
	while (src[rc])
		rc++;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (rc);
}
