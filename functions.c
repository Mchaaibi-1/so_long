/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:44:55 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 21:31:08 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	updatemapforplayermovement(char **map, int posX, int posY)
{
	if (map[posY][posX + 1] == 'C' || map[posY][posX + 1] == '0')
	{
		map[posY][posX + 1] = 'F';
		updatemapforplayermovement(map, posX + 1, posY);
	}
	if (map[posY][posX - 1] == 'C' || map[posY][posX - 1] == '0')
	{
		map[posY][posX - 1] = 'F';
		updatemapforplayermovement(map, posX - 1, posY);
	}
	if (map[posY + 1][posX] == 'C' || map[posY + 1][posX] == '0')
	{
		map[posY + 1][posX] = 'F';
		updatemapforplayermovement(map, posX, posY + 1);
	}
	if (map[posY - 1][posX] == 'C' || map[posY - 1][posX] == '0')
	{
		map[posY - 1][posX] = 'F';
		updatemapforplayermovement(map, posX, posY - 1);
	}
	return (0);
}

void	count_collectible(char **map, int x, int y)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count > 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

t_p	get_position(char **map, char c)
{
	t_p	p;
	int	i;
	int	j;

	i = 0;
	p = (t_p){0, 0};
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				p.x = i;
				p.y = j;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}

int	ft_check_sides(char **map, t_p pos)
{
	int	checker;

	checker = 0;
	if (map[pos.x][pos.y - 1] == 'F' || map[pos.x][pos.y + 1] == 'F' \
		|| map[pos.x - 1][pos.y] == 'F' || map[pos.x + 1][pos.y] == 'F')
		checker = 1;
	return (checker);
}

int	isexitaccessible(char **map)
{
	t_p	pos_player;
	t_p	pos_exit;

	pos_player = get_position(map, 'P');
	pos_exit = get_position(map, 'E');
	if (!ft_check_sides(map, pos_exit))
		return (0);
	if (!ft_check_sides(map, pos_player))
		return (0);
	return (1);
	puts("checking the accessibility ");
}
