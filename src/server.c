/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:14:23 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/14 18:58:44 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *buffer;

static void handle_signals(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;
	static int	i;
	int			buffer_size;

	(void) context;
	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
		{
			ft_printf("%d", (int)c);
			buffer_size = (int)c;
			buffer = malloc(sizeof(char) * (buffer_size + 1));
			if (!buffer)
				exit (0);
			i++;
		} else {
			buffer[i] = c;
			i++;
			if (!c)
			{
				// ft_printf("%s\n", buffer);
				if (kill(info->si_pid, SIGUSR2) < 0)
				{
					free(buffer);
					exit(0);
				}
				ft_bzero(buffer, buffer_size);
				i = 0;
				return ;
			}
			if (i == buffer_size)
			{
				// ft_printf("%s", buffer);
				ft_bzero(buffer, buffer_size);
				i = 0;
				return ;
			}
		}
		c = 0;
		bit = 0;
	}
	if (kill(info->si_pid, SIGUSR1) < 0)
		exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction sig;

	if (argc != 1)
	{
		ft_printf("Invalid number of arguments\n");
		return (1);
	}
	ft_printf("PID : %d\n", getpid());
	ft_bzero(&sig, sizeof(sig));
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	// if (buffer)
	// 	ft_printf("%s\n", buffer);
	while (1)
	{
		pause();
	}
}


// static void handle_signals(int signal, siginfo_t *info, void *context)
// {
// 	static int	bit;
// 	static int	c;
// 	static int	i;

// 	(void) context;
// 	if (signal == SIGUSR1)
// 		c |= (0x01 << bit);
// 	bit++;
// 	if (bit == 8)
// 	{
// 		buffer[i] = c;
// 		i++;
// 		if (!c)
// 		{
// 			ft_printf("%s\n", buffer);
// 			if (kill(info->si_pid, SIGUSR2) < 0)
// 			{
// 				free(buffer);
// 				exit(0);
// 			}
// 			ft_bzero(buffer, 4096);
// 			i = 0;
// 		}
// 		if (i == 4096)
// 		{
// 			ft_printf("%s", buffer);
// 			ft_bzero(buffer, 4096);
// 			i = 0;
// 		}
// 		c = 0;
// 		bit = 0;
// 	}
// 	if (kill(info->si_pid, SIGUSR1) < 0)
// 		exit(0);
// }

// int	main(int argc, char **argv)
// {
// 	struct sigaction sig;

// 	if (argc != 1)
// 	{
// 		ft_printf("Invalid number of arguments\n");
// 		return (1);
// 	}
// 	ft_printf("PID : %d", getpid());
// 	buffer = malloc(sizeof(char) * 4096);
// 	if (!buffer)
// 		return (0);
// 	ft_bzero(&sig, sizeof(sig));
// 	sig.sa_flags = SA_SIGINFO;
// 	sig.sa_sigaction = handle_signals;
// 	sigaction(SIGUSR1, &sig, NULL);
// 	sigaction(SIGUSR2, &sig, NULL);
// 	ft_printf("%s\n", buffer);
// 	while (1)
// 	{
// 		pause();
// 	}
// }
