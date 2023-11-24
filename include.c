/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:32:30 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/11/24 10:44:47 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

void	ft_putnbr_fd(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-');
		nb = nb * -1;
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0');
	else
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
}

void	ft_putstr_fd(char *s)
{
	int	i;

i = (0);
	if (!s[i])
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
	    i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	i++;
	return (i);
}