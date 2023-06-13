/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:18:09 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/13 15:28:04 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int nb;

static void handle_signals(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		printf("SIGUSR1 recu");
	// 	c |= (0x01 << bit);
	kill(info->si_pid, SIGUSR2);
	// // if (kill(info->si_pid, SIGUSR1) < 0)
	// 	// exit(0);
	// 	// printf("EH OH");
	// bit++;
	// if (bit == 8)
	// {
	// 	ft_printf("%c", c);
	// 	c = 0;
	// 	bit = 0;
	// }
}

int	main(int argc, char **argv)
{
	struct sigaction sig;

	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("PID : %d", getpid());
	(void) argc;
	(void) argv;
	// ft_bzero(&sig, sizeof(sig));
	sig.sa_sigaction = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
		// kill(ft_atoi(argv[1]), SIGUSR2);
	}
}

/////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static void handle_signals(int signal, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
		printf("SIGUSR1 recu");
	kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction sig;

	printf("PID : %d", getpid());
	sig.sa_sigaction = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
