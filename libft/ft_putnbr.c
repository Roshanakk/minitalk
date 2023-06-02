/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:38:02 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/10 11:39:34 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *nbr)
{
	write(1, &c, 1);
	(*nbr)++;
}

void	ft_putnbr(int n, int *nbr)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", nbr);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', nbr);
			ft_putnbr(-n, nbr);
		}
		else if (n / 10 == 0)
			ft_putchar(n + '0', nbr);
		else if (n / 100 == 0)
		{
			ft_putchar(n / 10 + '0', nbr);
			ft_putchar(n % 10 + '0', nbr);
		}
		else
		{
			ft_putnbr(n / 10, nbr);
			ft_putchar(n % 10 + '0', nbr);
		}
	}
}

void	ft_putnbr_u(unsigned int n, int	*nbr)
{
	if (n == 4294967295)
		ft_putstr("4294967295", nbr);
	else
	{
		if (n / 10 == 0)
			ft_putchar(n + '0', nbr);
		else if (n / 100 == 0)
		{
			ft_putchar(n / 10 + '0', nbr);
			ft_putchar(n % 10 + '0', nbr);
		}
		else
		{
			ft_putnbr(n / 10, nbr);
			ft_putchar(n % 10 + '0', nbr);
		}
	}
}
