/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roxy <Roxy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:08:46 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/12 13:56:52 by Roxy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// void	ft_putchar_bin(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr_bin(unsigned long long nb, int *res)
// {
// 	char	*base;
//     // char    *str;

// 	res = 0;
// 	base = "01";
// 	if (nb < 2)
// 		*res = ft_atoi(&base[nb]);
// 	else
// 	{
// 		ft_putnbr_bin(nb / 2);
// 		*res = *res + ft_atoi(&base[nb % 2]);
// 	}
// 	return (0);
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


// int main()
// {
//     // char *str;
//     // str = ft_strdup("\0");
//     ft_putnbr_bin(1);
//     printf("\n");
//     ft_putnbr_bin(2);
//     printf("\n");
//     ft_putnbr_bin(4);
//     printf("\n");
//     ft_putnbr_bin(8);
//     printf("\n");
//     ft_putnbr_bin(16);
//     printf("\n");
//     ft_putnbr_bin(32);
//     printf("\n");
//     ft_putnbr_bin(64);
//     printf("\n");
//     ft_putnbr_bin(128);
//     printf("\n");
//     ft_putnbr_bin(256);
//     // ft_putnbr_bin(42);
// }
