/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:32:34 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/26 12:09:10 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_image(t_map *info)
{
	if (!info->player || !info->wall || !info->collect || !info->exit)
	{
		write(1, "Error\nimage error\n", 18);
		exit(1);
	}
}

void	ft_image(t_map *info)
{
	ft_putnbr(0);
	ft_putstr("\n");
	info->player = mlx_xpm_file_to_image(info->mlx,
			"textures/player.xpm", &info->wid, &info->heigh);
	info->back = mlx_xpm_file_to_image(info->mlx,
			"textures/back.xpm", &info->wid, &info->heigh);
	info->wall = mlx_xpm_file_to_image(info->mlx,
			"textures/wall.xpm", &info->wid, &info->heigh);
	info->collect = mlx_xpm_file_to_image(info->mlx,
			"textures/collect.xpm", &info->wid, &info->heigh);
	info->exit = mlx_xpm_file_to_image(info->mlx,
			"textures/exit.xpm", &info->wid, &info->heigh);
	check_image(info);
	items_images(info);
}

void	items_images(t_map *info)
{
	int	i;
	int	k;

	i = 0;
	while (i < info->x)
	{
		k = 0;
		while (k <= info->y)
		{
			if (info->map[i][k] == 'P')
				mlx_put_image_to_window(info->mlx, info->window,
					info->player, k * T_SIZE, i * T_SIZE);
			else if (info->map[i][k] == 'E')
				mlx_put_image_to_window(info->mlx, info->window,
					info->exit, k * T_SIZE, i * T_SIZE);
			else if (info->map[i][k] == 'C')
				mlx_put_image_to_window(info->mlx, info->window,
					info->collect, k * T_SIZE, i * T_SIZE);
			else if (info->map[i][k] == '1')
				mlx_put_image_to_window(info->mlx, info->window,
					info->wall, k * T_SIZE, i * T_SIZE);
			k++;
		}
		i++;
	}
}
