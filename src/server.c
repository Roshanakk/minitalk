/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:14:23 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/13 18:35:56 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void handle_signals(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

	(void) context;
	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	// else if (signal == SIGUSR1)
	// 	c &= ~(0x01 << bit);
	bit++;
	if (bit == 8)
	{
		// usleep(100);
		// ft_printf("on envoie SIGUSR2\n");
		// if (kill(info->si_pid, SIGUSR2) < 0)
		// 	exit(0);
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction sig;

	// if (argc != 1)
	// {
	// 	ft_printf("Error\n");
	// 	return (1);
	// }
	sig.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d", getpid());
	// (void) argc;
	// (void) argv;
	// ft_bzero(&sig, sizeof(sig));
	sig.sa_sigaction = handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}



// static void handle_signals(int signal, siginfo_t *info, void *context)
// {
// 	static pid_t client_pid;

// 	(void) context;
// 	if (!client_pid)
// 		client_pid = info->si_pid;
// 	if (signal == SIGUSR1)
// 		ft_printf("SIGUSR1 recu");
// 	kill(client_pid, SIGUSR2);
// }

// int	main(int argc, char **argv)
// {
// 	struct sigaction sig;

// 	sig.sa_flags = SA_SIGINFO;
// 	ft_printf("PID : %d", getpid());
// 	sig.sa_sigaction = handle_signals;
// 	sigaction(SIGUSR1, &sig, NULL);
// 	sigaction(SIGUSR2, &sig, NULL);
// 	// signal(SIGUSR1, handle_signals);
// 	// signal(SIGUSR2, handle_signals);
// 	while (1)
// 		pause();
// 	return (0);
// }

