/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:44:24 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/05/31 15:44:35 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*str;
	char		*s_bis;

	i = 0;
	s_bis = (char *)s;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str || !s)
		return (0);
	while (s_bis[i])
	{
		str[i] = s_bis[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}