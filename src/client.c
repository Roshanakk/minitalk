/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:27:54 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/14 18:48:19 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <sys/types.h>
#include <sys/wait.h>

int bit_received;

static void handle_signals(int signal)
{
	if (signal == SIGUSR1)
		bit_received = 1;
	if (signal == SIGUSR2)
		ft_printf("\nMessage successfully received !\n");
}

void send_message(char c, pid_t server_pid)
{
	int	bit;

	bit = 0;
	
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
	}
}

// void send_len(int len, pid_t server_pid)
// {
// 	int	bit;

// 	bit = 0;
	
// 	while (bit < 8)
// 	{
// 		if ((len & (1 << bit)))
// 		{	
// 			if (kill(server_pid, SIGUSR1) < 0)
// 				exit (0);
// 		}
// 		else
// 		{	
// 			if (kill(server_pid, SIGUSR2) < 0)
// 				exit (0);			
// 		}
// 		bit++;
// 		bit_received = 0;
// 		while (!bit_received);
// 	}
// }

int check_args(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments");
		return (0);
	}
	if (!ft_alldigit(argv[1]) || ft_atoi(argv[1]) > 4194304)
	{
		ft_printf("Invalid PID");
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	int i;

	bit_received = 1;
	if (!check_args(argc, argv))
		return (0);
	ft_bzero(&sig, sizeof(sig));
	sig.sa_handler = handle_signals;
	if (sigaction(SIGUSR1, &sig, NULL) < 0 
		|| sigaction(SIGUSR2, &sig, NULL) < 0)
		return (0);
	i = 0;
	// send_len(ft_strlen(argv[2]), ft_atoi(argv[1]));
	send_message((char)(ft_strlen(argv[2])), ft_atoi(argv[1]));
	while (argv[2][i])
	{
		send_message(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	send_message(argv[2][i], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
