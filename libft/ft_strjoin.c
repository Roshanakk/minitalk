/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:50:03 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/14 11:29:39 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char c)
{
	char	*string;
	size_t	i;

	if (!c)
		return ((char *)s1);
	if (!s1)
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!string)
		return (0);
	i = 0;
	while (((char *)s1)[i])
	{
		string[i] = ((char *)s1)[i];
		i++;
	}
	string[i] = c;
	string[i + 1] = '\0';
	return (string);
}
