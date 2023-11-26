/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:03:21 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/26 12:24:04 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_lines_length(char **map, int numberOfLines)
{
	int		index;
	int		firstlinelength;
	int		currentlinelength;

	index = 0;
	firstlinelength = ft_strlen(map[0]);
	while (index < numberOfLines - 1)
	{
		currentlinelength = ft_strlen(map[index]);
		if (firstlinelength != currentlinelength)
		{
			ft_putstr("ERROR\n");
			exit(1);
		}
		index++;
	}
	currentlinelength = ft_strlen(map[index]);
	if (firstlinelength - 1 != currentlinelength)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
}

void	validatefirstlastline(char *line1, char *line2)
{
	int		index;

	index = 0;
	if (!line1[0] || !line2[0])
	{
		write(1, "Error\nmap error\n", 16);
		exit(1);
	}
	while (line1[index] && line2[index])
	{
		if (line1[index] == '\n' || line2[index] == '\n')
			break ;
		if (line1[index] != '1' || line2[index] != '1')
		{
			write(1, "Error map error\n", 16);
			exit(1);
		}
		index++;
	}
}

void	checkwall(char **map, int numberOfLines)
{
	int	index;
	int	length;

	index = 1;
	length = ft_strlen(map[numberOfLines - 1]);
	validatefirstlastline(map[0], map[numberOfLines - 1]);
	while (map[index])
	{
		if (map[index][0] != '1' || map[index][length - 1] != '1')
		{
			write(1, "Error map error\n", 16);
			exit(1);
		}
		index++;
	}
}

void	render(t_map *info)
{
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, info->y * T_SIZE,
			info->x * T_SIZE, "so_long");
	ft_image(info);
	mlx_hook(info->window, 2, 0, &key_hook, info);
	mlx_hook(info->window, 17, 0, &exite, info);
	mlx_loop(info->mlx);
}

int	main(int ac, char **av)
{
	t_map	info;

	if (ac != 2)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	else
	{
		whish_map_name(av[1]);
		whish_map(av[1], &info);
		verify_lines_length(info.map, info.x);
		checkwall(info.map, info.x);
		checkmap(info.map, info.x);
		path(info.map, info.x, info.y);
		render(&info);
	}
}
