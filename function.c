/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:21:52 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/26 12:18:36 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectible(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	update_map(t_map *info, int posX, int posY, t_p p)
{
	if (info->map[posX][posY] == 'C' || info->map[posX][posY] == '0')
	{
		info->map[posX][posY] = 'P';
		ft_putnbr(++info->action);
		ft_putstr("\n");
		if (info->map[posX][posY] == 'C')
			info->collectible--;
		info->map[p.x][p.y] = '0';
		mlx_put_image_to_window(info->mlx, info->window,
			info->player, posY * T_SIZE, posX * T_SIZE);
		mlx_put_image_to_window(info->mlx, info->window,
			info->back, p.y * T_SIZE, p.x * T_SIZE);
	}
	if (info->map[posX][posY] == 'E' && collectible(info->map) == 0)
	{
		ft_putstr("You Win\n");
		exit(0);
	}
}

int	key_hook(int key, t_map *info)
{
	t_p	p;

	p = get_position(info->map, 'P');
	info->collectible = collectible(info->map);
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 126)
		update_map(info, p.x - 1, p.y, p);
	else if (key == 1 || key == 125)
		update_map(info, p.x + 1, p.y, p);
	else if (key == 0 || key == 123)
		update_map(info, p.x, p.y - 1, p);
	else if (key == 2 || key == 124)
		update_map(info, p.x, p.y + 1, p);
	return (0);
}
