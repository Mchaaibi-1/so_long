/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:32:26 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 19:54:49 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	whish_map_name(char *map)
{
	int	i;

	i = ft_strlen(map) - 4;
	if (ft_strncmp(&map[i], ".ber", 4))
	{
		ft_putstr("Error in map");
		exit (1);
	}
}

void	ft_free(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	whish_map(const char *map, t_map *info)
{
	int		fd;
	int		j;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
	info->x = x(map);
	info->map = malloc(sizeof(char *) * (info->x + 1));
	j = 0;
	info->map[j] = get_next_line(fd);
	while (info->map[j])
	{
		j++;
		info->map[j] = get_next_line(fd);
		if (info->map[j] && info->map[j][0] == '\n')
		{
			ft_putstr("Error\n");
			exit(1);
		}
	}
	info->map[j] = NULL;
	info->y = ft_strlen(info->map[j - 1]);
}

void	checkplayerandexitcount(int playerCount, int exitCount)
{
	if (playerCount > 1 || exitCount > 1) 
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (playerCount < 1 || exitCount < 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	countplayercollectibleexit(char *line, int *playerCount, \
		int *collectibleCount, int *exitCount)
{
	int	index;

	index = 0;
	while (line[index] && line[index] != '\n')
	{
		if (line[index] == 'P')
			(*playerCount)++;
		else if (line[index] == 'C')
			(*collectibleCount)++;
		else if (line[index] == 'E')
			(*exitCount)++;
		else if (line[index] != '1' && line[index] != '0')
		{
			ft_putstr("Error\n");
			exit(1);
		}
		index++;
	}
}
