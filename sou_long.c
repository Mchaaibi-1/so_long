/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sou_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:03:21 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/24 11:17:13 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void long_line()

int	main(int ac, char **av)
{
	int		i;
	t_map	info;

	i = 0;

	if (ac == 2)
	{
		whish_map_name(av[1])
		whish_map(av[1], &info);
		long_line(info);
	}
}

