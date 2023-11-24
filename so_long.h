/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sou_long.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:59:30 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/24 10:47:11 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOU_LONG_H
# define SOU_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"


typedef struct positon
{
	int	x;
	int	y;
}t_position;

typedef struct map
{
	int		len;
	int		x;
	int		y;
	int		action;
	char	**map;
	void	*window;
	int		collect;
	void	*back;
	void	*exit;
	void	*wall;
	void	*player;
	int		wid;
	int		heigh;
	void	*mlx;
}t_map;

char	*ft_strrchr(const char *s, int c);
void	ft_putnbr_fd(int n);
void	ft_putstr_fd(char *s);
int	ft_strlen(const char *s);

#endif