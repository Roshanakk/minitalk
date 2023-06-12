/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roxy <Roxy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:27:54 by rraffi-k          #+#    #+#             */
/*   Updated: 2023/06/12 18:58:01 by Roxy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <sys/types.h>
#include <sys/wait.h>

int x;

// void handle_signals(int signal)
// {
// 	if (signal == SIGUSR1)
// 		ft_printf("signal 1");
// 	if (signal == SIGUSR2)
// 		ft_printf("signal 2");
// }

static void handle_signals(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("message received");
}

void send_message(char c, pid_t server_pid)
{
	int	bit;
	int success;
	// int	i;

	bit = 0;
	// i = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)))
		{
			success = kill(server_pid, SIGUSR1);
			if (success < 0)
				exit (0);
		}
		else
		{
			success = kill(server_pid, SIGUSR2);
			if (success < 0)
				exit (0);			
		}
		usleep(100);
		bit++;
	}
}

int main(int argc, char **argv)
{
	struct sigaction sig;
	char	*buffer;
	// int k;
	int i;
	int j;

	ft_putstr_fd(ft_itoa(getpid()));
	(void) argc;
	(void) argv;
	ft_bzero(&sig, sizeof(sig));
	sig.sa_handler = &handle_signals;
	sigaction(SIGUSR1, &sig, NULL);
	// sigaction(SIGUSR2, &sig, NULL);
	if (argc > 1)
	{
		buffer = ft_strdup("\0");
		if (!buffer)
			return (0);
		j = 2;
		while (argv[j])
		{
			if (j > 2)
			{
				buffer = ft_strjoin(buffer, " ");
				if (!buffer)
				{
					free(buffer);
					return (0);
				}				
			}
			buffer = ft_strjoin(buffer, argv[j]);
			if (!buffer)
			{
				free(buffer);
				return (0);
			}
			j++;
		}
		// j = 2;
		// while (argv[j])
		// {
			i = 0;
			while (buffer[i])
			{
				send_message(buffer[i], ft_atoi(argv[1]));
				i++;
			}
			// if (argv[j + 1])
			// 	send_message(' ', ft_atoi(argv[1]));
			// j++;	
		// }
		while (1)
			pause();
	}
	else
		return (0);

}
