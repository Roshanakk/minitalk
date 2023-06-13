/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:27:54 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/13 15:29:09 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <sys/types.h>
#include <sys/wait.h>

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	n;

	i = 0;
	n = 1;
	res = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		n = -n;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	return (n * res);
}

static void handle_signals(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("SIGUSR2 recu");
}

void send_message(pid_t server_pid)
{
	kill(server_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	char	*buffer;

	sig.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);

	send_message(ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
