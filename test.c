/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:03:49 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/02 17:34:11 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
    char *str = "coquillage";
    int nb = 0;
    printf("%d\n", (str[0] & 127));
    printf("%d\n", (str[0] & 127) >> 1);
    printf("%d\n", (str[0] & 127) >> 2);
    // printf("%d\n", str[0] << 1);
    if ((str[0] & 127))
        nb = nb + 1;

    if ((str[0] & 127) >> 1)
    {
        nb = nb * 10 + 1;
    } else {
        nb = nb * 10;
    }

    if ((str[0] & 127) >> 2)
    {
        nb = nb * 100 + 1;
    } else {
        nb = nb * 100;
    }

    if ((str[0] & 127) >> 3)
    {
        nb = nb * 1000 + 1;
    } else {
        nb = nb * 1000;
    }

    if ((str[0] & 127) >> 4)
    {
        nb = nb * 10000 + 1;
    } else {
        nb = nb * 10000;
    }
    printf("%d, %c\n", nb, nb);
    return (0);
}