/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:05 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/13 15:27:47 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <sys/types.h>
#include <sys/wait.h>

// int bit_received;

static void handle_signals(int signal)
{
	if (signal == SIGUSR2)
	{
		// bit_received = 1;
		printf("SIGUSR2 recu");
	}
}

void send_message(char c, pid_t server_pid)
{
	int	bit;
	int success;

	(void) c;
	kill(server_pid, SIGUSR1);
	// bit = 0;
	// // while (!bit_received);
	// while (bit < 8)
	// {
	// 	if ((c & (1 << bit)))
	// 	{
	// 		if (kill(server_pid, SIGUSR1) < 0)
	// 			exit (0);
	// 	}
	// 	else
	// 	{
	// 		if (kill(server_pid, SIGUSR2) < 0)
	// 			exit (0);			
	// 	}
	// 	usleep(100);
	// 	bit++;
	// 	// bit_received = 0;
	// }
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	char	*buffer;
	int i;

	// bit_received = 1;
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments");
		return (0);
	}
	// ft_bzero(&sig, sizeof(sig));
	sig.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	// signal(SIGUSR1, handle_signals);
	// signal(SIGUSR2, handle_signals);
	// buffer = ft_strdup("\0");
	// if (!buffer)
	// 	return (0);			
	// buffer = ft_strjoin(buffer, argv[2]);
	// if (!buffer)
	// {
	// 	free(buffer);
	// 	return (0);
	// }
	// i = 0;
	// while (argv[2][i])
	// {
		// signal(SIGUSR1, handle_signals);
		// signal(SIGUSR2, handle_signals);
		send_message(argv[2][i], ft_atoi(argv[1]));
		// printf("%s", argv[2]);
		// send_message(argv[2][i], ft_atoi(argv[1]));
	// 	i++;
	// }
	while (1)
		pause();
	return (0);
}


/////////////////
/*
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
		printf("SIGUSR2 recu");
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
*/