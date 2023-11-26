/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:59:30 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/25 21:31:42 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define T_SIZE 32
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_p
{
	int	x;
	int	y;

}t_p;

typedef struct map
{
	int		len;
	int		x;
	int		y;
	int		action;
	int		collectible;
	char	**map;
	void	*window;
	int		*collect;
	void	*exit;
	void	*back;
	void	*wall;
	void	*player;
	int		wid;
	int		heigh;
	void	*mlx;
}t_map;

void	ft_free(char **map);
char	*ft_strrchr(char *s, int c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	whish_map_name(char *map);
void	whish_map(const char *map, t_map *info);
int		x(const char *map);
void	checkwall(char **map, int numberOfLines);
void	countplayercollectibleexit(char *line, \
		int *playerCount, int *collectibleCount, int *exitCount);
void	checkmap(char **mapLines, int numberOfLines);
char	**duplicate_map(char **map, int x);
void	path(char **map, int x, int y);
int		sexitaccessible(char **map);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_image(t_map *info);
void	items_images(t_map *info);
t_p		get_position(char **map, char c);
int		key_hook(int key, t_map *info);
int		exite(t_map *info);
void	checkplayerandexitcount(int playerCount, int exitCount);
int		updatemapforplayermovement(char **map, int posX, int posY);
void	count_collectible(char **map, int x, int y);
int		isexitaccessible(char **map);

void	ft_pirnt_map(char **map, int x, int y);
#endif
