/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:27:54 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/13 18:53:42 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <sys/types.h>
#include <sys/wait.h>

int bit_received;

static void handle_signals(int signal)
{
	if (signal == SIGUSR1)
	{
		// ft_printf("SIGUSR2 recu\n");
		bit_received = 1;
		// ft_printf("bit received value : %d\n", bit_received);
	}
	if (signal == SIGUSR2)
		ft_printf("message received\n");
}

void send_message(char c, pid_t server_pid)
{
	int	bit;

	bit = 0;
	// ft_printf("bit received value : %d\n", bit_received);
	
	while (bit < 8)
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
		bit++;
		bit_received = 0;
		while (!bit_received);
		// usleep(100);
	}
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	int i;

	bit_received = 1;
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments");
		return (0);
	}
	ft_bzero(&sig, sizeof(sig));
	sig.sa_handler = handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	i = 0;
	while (argv[2][i])
	{
		send_message(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	while (1)
		pause();
	return (0);
}


////////////////////////////////////////////////////////////


// static void action(int signal)
// {
// 	if (signal == SIGUSR2)
// 		ft_printf("SIGUSR2 recu");
// 	else
// 		ft_printf("SIGUSR2 recu");
// }

// void send_message(pid_t server_pid)
// {
// 	kill(server_pid, SIGUSR1);
// 	usleep(100);
// }

// int main(int argc, char **argv)
// {
// 	signal(SIGUSR1, action);
// 	signal(SIGUSR2, action);
// 	send_message(ft_atoi(argv[1]));
// 	while (1)
// 		pause();
// 	return (0);
// }
