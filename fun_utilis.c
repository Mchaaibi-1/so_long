/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_utilis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:37:28 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 18:27:32 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exite(t_map *info)
{
	mlx_destroy_window(info->mlx, info->window);
	exit(0);
}

void	coll(int collectiblecount)
{
	if (collectiblecount < 1)
	{
		ft_putstr("ERROR\n");
		exit(1);
	}
}

void	checkmap(char **mapLines, int numberOfLines)
{
	int	playercount;
	int	collectiblecount;
	int	exitcount;
	int	i;

	i = 0;
	playercount = 0;
	collectiblecount = 0;
	exitcount = 0;
	while (i < numberOfLines)
	{
		if (!ft_strncmp(mapLines[i], "\n", 1) || 
			!ft_strncmp(mapLines[numberOfLines - 1], "\n", 1))
		{
			ft_putstr("ERROR\n");
			exit(1);
		}
		countplayercollectibleexit(mapLines[i], &playercount, 
			&collectiblecount, &exitcount);
		i++;
	}
	checkplayerandexitcount(playercount, exitcount);
	coll(collectiblecount);
}

char	**duplicate_map(char **map, int x)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = malloc(sizeof(char *) * x + 1);
	while (i < x)
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
