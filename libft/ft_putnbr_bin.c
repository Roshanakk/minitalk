/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:08:46 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/02 15:55:09 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_bin(unsigned long long nb)
{
	char	*base;
    // char    *str;
    int res;

	base = "01";
	if (nb < 2)
		res = ft_atoi(&base[nb]);
	else
	{
		ft_putnbr_bin(nb / 2);
		res = res + ft_atoi(&base[nb % 2]);
	}
}

// void	ft_putchar_bin(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr_bin(unsigned long long nb)
// {
// 	char	*base;

// 	base = "01";
// 	if (nb == 0)
// 		ft_putchar_bin(base[0]);
// 	if (nb < 2)
// 		ft_putchar_bin(base[nb]);
// 	else
// 	{
// 		ft_putnbr_bin(nb / 2);
// 		ft_putchar_bin(base[nb % 2]);
// 	}
// }

int main()
{
    char *str;
    str = ft_strdup("\0");
    ft_printf("%d", ft_putnbr_bin(42));
    // ft_putnbr_bin(42);
}
