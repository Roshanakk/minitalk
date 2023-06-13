/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roxy <Roxy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:27:54 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/13 11:57:00 by Roxy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <sys/types.h>
#include <sys/wait.h>

int bit_received;

static void handle_signals(int signal)
{
	static int	message_received;

	if (!message_received)
	{
		if (signal == SIGUSR1)
			ft_printf("message received");
		message_received = 1;
		bit_received = 1;
	}
}

void send_message(char c, pid_t server_pid)
{
	int	bit;
	int success;
	// int	i;

	bit = 0;
	// i = 0;
	// while (buffer[i])
	// {
		// printf("%c", buffer[i]);
	while (bit < 8)
	{
		if (bit_received)
		{
			if ((c & (1 << bit)))
			{
				if (kill(server_pid, SIGUSR1) < 0)
					exit (0);
			}
			else
			{
				if (kill(server_pid, SIGUSR2) < 0)
					exit (0);			
			}
			usleep(100);
			bit++;		
		}
		bit_received = 0;
	}
	// 	i++;
	// }
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	// char	*buffer;
	// int k;
	int i;
	// int j;

	ft_bzero(&sig, sizeof(sig));
	sig.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	bit_received = 1;
	// sigaction(SIGUSR2, &sig, NULL);
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments");
		return (0);
	}
	// buffer = ft_strdup("\0");
	// if (!buffer)
	// 	return (0);			
	// buffer = ft_strjoin(buffer, argv[2]);
	// if (!buffer)
	// {
	// 	free(buffer);
	// 	return (0);
	// }
	i = 0;
	while (argv[2][i])
	{
		// send_message(buffer[i], ft_atoi(argv[1]));
		// printf("%s", argv[2]);
		send_message(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	while (1)
		pause();
	return (0);
}
