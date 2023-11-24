/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:57:34 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/24 00:57:35 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	whish_line(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1[0] || !s2[0])
		ft_putstr("ERROR\n");
	while (s1[i] && s2[i])
	{
		if (s1[i] == '\n' || s2[i] == '\n')
			break ;
		if (s1[i] != '1' || s2[i] != '1')
			ft_putstr("ERROR\n");
		i++;
	}
}

void	whish_size(char **s, int n)
{
	int	i;
	int	len0;
	int	len1;

	i = 1;
	len0 = ft_strlen(s[0]);
	while (i < n - 1)
	{
		len1 = ft_strlen(s[i]);
		if (len0 != len1)
			erreur();
		i++;
	}
	len1 = ft_strlen(s[i]);
	if (len0 != len1 + 1)
		erreur();
	if (len0 > 41)
	{
		write(1, "Error\nmap so_long\n", 18);
		exit(1);
	}
	check_long(len1, n);
}

void	whish_wall(char **s, int n)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(s[n - 1]);
	whish_line(s[0], s[n - 1]);
	while (s[i])
	{
		if (s[i][0] != '1' || s[i][len - 1] != '1')
		{
			write(1, "Error\n", 6)
			exit(1);
		}
		i++;
	}
}

int	x(char *map)
{
	int		fd;
	int		x;
	char	*str;

	x = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_putstr(ERROR);
	s = get_next_line(fd);
	if (!str)
		ft_putstr(ERROR);
	x++;
	while (str)
	{
		free(s);
		s = get_next_line(fd);
		x++;
	}
	if (!str)
		x--;
	return (x);
}