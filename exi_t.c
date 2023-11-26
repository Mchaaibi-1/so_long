/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exi_t.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:53:25 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 21:33:09 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_exit_accessible(char **map)
{
	t_p	exitpos;

	exitpos = get_position(map, 'E');
	if (map[exitpos.x][exitpos.y - 1] != 'F')
		return (0);
	if (map[exitpos.x][exitpos.y + 1] != 'F')
		return (0);
	if (map[exitpos.x - 1][exitpos.y] != 'F')
		return (0);
	if (map[exitpos.x + 1][exitpos.y] != 'F')
		return (0);
	return (1);
}

t_p	find_player(char **map, int x, int y)
{
	t_p	p;
	int	i;
	int	j;

	i = 0;
	p.x = 0;
	p.y = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (map[i][j] == 'P')
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

void	ft_pirnt_map(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	path(char **map, int x, int y)
{
	t_p		p;
	int		cheker;
	char	**new_map;

	new_map = duplicate_map(map, x);
	p = find_player(map, x, y);
	updatemapforplayermovement(new_map, p.x, p.y);
	count_collectible(new_map, x, y);
	cheker = isexitaccessible(new_map);
	if (!cheker)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	ft_free(new_map);
}
