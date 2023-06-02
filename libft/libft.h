/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:18:47 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/02 15:52:44 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *arg0, ...);
void	ft_case(char c, va_list args, int *nbr);
void	ft_putstr_bis(const char *s, int start, int end, int *nbr);
void	ft_putchar(char c, int *nbr);
void	ft_putnbr(int n, int *nbr);
void	ft_putnbr_u(unsigned int n, int	*nbr);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *nbr);
void	ft_putstr_fd(char *s);
void	ft_putnbr_base_long(unsigned long long nb, int *nbr);
void	ft_putnbr_base(unsigned int nb, char c, int *nbr);
void	ft_intochar(int a, int *nbr);
void	ft_pointer(char c, va_list args, int *nbr);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
int	    ft_atoi(const char *nptr);
int	    ft_putnbr_bin(unsigned long long nb);
char	*ft_strjoin(char const *s1, char const *s2);
// void	ft_putchar_bin(char c);
// void	ft_putnbr_bin(unsigned long long nb);

#endif