/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:32:26 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/24 10:32:27 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_long *data)
{
	int	player;
	int	collect;
	int	exit;

	exit = 0;
	collect = 0;
	playe = 0;
	whish_line(info);
	whish_wall(info);
	whish_exit_collectible_player(info, player, exit, collect);
	whish_size(info);
}

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
void	whish_map(char *map, t_map *info)
{
	int		j;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
        ft_putstr("ERROR IN OPEN FILE")
    info->x = x(map);
	info->map = malloc(sizeof(char *) * info->x + 1);
	info->map[0] = get_next_line(fd);
	j = 1;
	while (j < info->x)
    {
		info->map[i] = get_next_line(fd);
        i++;
    }
	info->map[i] = NULL;
	info->y = ft_strlen(info->map[i - 1]) - 1;
	//info->x--;
}
